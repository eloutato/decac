package decac

import scala.collection.mutable.Set
import scala.collection.mutable.HashSet
import scala.collection.mutable.HashMap
import scala.collection.mutable.GraphLattice
import jllvm._

/* class TypeDefinition(cons: TypeConstructor,n: String,context: Module) extends Definition {
  override val name = n
  override val scope = {context.define(this) ; context }
  val constructor = { cons.declare(name) ; cons }
} */

abstract class TypeConstructor(alphas: List[TypeVariable]) {
  protected var strName: Option[String] = None
  def declare(str: String): String = strName match {
    case Some(n) => n
    case None => {
      strName = Some(str)
      str
    }
  }
  def name: String = strName match {
    case Some(n) => n
    case None => getClass().getName() + '@' + Integer.toHexString(hashCode())
  }
  val parameters: List[TypeVariable] = alphas
  assert(parameters.forall(param => param.universal))
  protected val specializations = new HashMap[List[MonoType],LLVMType]()
  
  def compile(params: List[MonoType]): LLVMType
  def resolve(params: List[MonoType]): LLVMType
  def represent(params: List[MonoType]): MonoType
  protected def getSpecialization(params: List[MonoType]): Option[LLVMType] = {
    for((specialization,llvmType) <- specializations)
      if(specialization.zip(params).forall(p => p._1 == p._2))
        return Some(llvmType)
    None
  }
  def allSpecializations: Iterable[LLVMType] = specializations.values
}

class TypeExpressionConstructor(alphas: List[TypeVariable],t: MonoType) extends TypeConstructor(alphas) {
  assert(t.variables.forall(tvar => alphas.contains(tvar)))
  protected val tau: MonoType = t
  
  override def compile(params: List[MonoType]): LLVMType = specializations.get(params) match {
    case Some(t) => t
    case None => {
      val result = represent(params).compile
      specializations.put(params,result)
      result
    }
  }
  override def resolve(params: List[MonoType]): LLVMType = compile(params)
  override def represent(params: List[MonoType]): MonoType = {
    parameters.zip(params).foldLeft(tau)((result: MonoType,spec: Tuple2[TypeVariable,MonoType]) => result.mapT((sig: MonoType) => if(sig == spec._1) spec._2 else sig))
  }
}

class OpenSumConstructor(alphas: List[TypeVariable],addends: List[Tuple2[String,RecordType]],loopNode: Option[MonoType]) extends TypeConstructor(alphas) {
  protected val recurser = new OpaqueType
  protected var cases: List[Tuple2[String,RecordType]] = loopNode match {
    case Some(loop) => addends.map(addend => (addend._1,addend._2.mapT((sig: MonoType) => if(sig == loop) recurser else sig).asInstanceOf[RecordType]))
    case None => addends
  }
  
  def extend(addend: Tuple2[String,RecordType],loopNode: Option[MonoType]): Unit = {
    assert(addend._2.variables.forall(tvar => alphas.contains(tvar)))
    if(!cases.contains((c: Tuple2[String,RecordType]) => c._1 == addend._1))
      cases = loopNode match {
        case Some(loop) => (addend._1,addend._2.mapT((sig: MonoType) => if(sig == loop) recurser else sig).asInstanceOf[RecordType]) :: cases
        case None => addend :: cases
      }
  }
  
  protected val tagRepresentation = new LLVMPointerType(LLVMIntegerType.i8,0)
  
  override def compile(params: List[MonoType]): LLVMType = getSpecialization(params) match {
    case Some(t) => t
    case None => {
      val temporary = new LLVMStructType(List(tagRepresentation,new LLVMOpaqueType).toArray,true)
      specializations.put(params,temporary)
      temporary
    }
  }
  override def represent(params: List[MonoType]): MonoType = {
    val sum = {
      val sum = new SumType(cases)
      val recursive = new RecursiveType(sum,Some(recurser))
      if(TypeOrdering.equiv(recursive,sum))
        sum
      else
        recursive
    }
    parameters.zip(params).foldLeft(sum)((result: MonoType,spec: Tuple2[TypeVariable,MonoType]) => result.mapT((sig: MonoType) => if(sig == spec._1) spec._2 else sig))
  }
  
  protected def caseRepresentation(which: Int): LLVMType = {
    assert(which < cases.length)
    if(cases.forall(c => TypeOrdering.equiv(c._2,EmptyRecord)))
      tagRepresentation
    else
      new LLVMStructType(List(tagRepresentation,cases.apply(which)._2.compile).toArray,true)
  }
  
  override def resolve(params: List[MonoType]): LLVMType = represent(params).compile
}

object ExceptionConstructor extends OpenSumConstructor(Nil,List(("AnyException",EmptyRecord)),None) {
  //new TypeDefinition(this,"Exception",StandardLibrary)
}

case class SkolemConstructor(shape: RecordType) extends TypeConstructor(shape.variables.toList.filter(svar => svar.isInstanceOf[TypeVariable]).map(svar => svar.asInstanceOf[TypeVariable])) {
  var witnesses = new HashSet[MonoType]()
  
  override def compile(params: List[MonoType]): LLVMType = getSpecialization(params) match {
    case Some(op) => op
    case None => {
      val result = (new OpaqueType).compile
      specializations.put(params,result)
      result
    }
  }
  override def resolve(params: List[MonoType]): LLVMType = represent(params).compile
  override def represent(params: List[MonoType]): MonoType = {
    val specialize = (spec: MonoType) => parameters.zip(params).foldLeft(spec)((result: MonoType,specs: Tuple2[TypeVariable,MonoType]) => result.mapT((sig: MonoType) => if(sig == specs._1) specs._2 else sig))
    witnesses.toList.sortWith((x,y) => specialize(x).sizeOf >= specialize(y).sizeOf).head
  }
  def witness(w: MonoType): Unit = {
    assert(w.variables.forall(svar => parameters.contains(svar)))
    witnesses.add(w)
  }
}

object TopSkolem extends SkolemConstructor(EmptyRecord)
object BottomSkolem extends SkolemConstructor(EmptyRecord)

object SkolemOrdering extends PartialOrdering[SkolemConstructor] {
  implicit val typeOrdering = TypeOrdering
  override def lt(x: SkolemConstructor,y: SkolemConstructor): Boolean =  x == BottomSkolem || x.shape < y.shape
  override def equiv(x: SkolemConstructor,y: SkolemConstructor): Boolean = x.shape == y.shape
  override def gt(x: SkolemConstructor,y: SkolemConstructor): Boolean = y == BottomSkolem || x.shape > y.shape
  override def lteq(x: SkolemConstructor,y: SkolemConstructor): Boolean = x == BottomSkolem || x.shape <= y.shape
  override def gteq(x: SkolemConstructor,y: SkolemConstructor): Boolean = y == BottomSkolem || x.shape >= y.shape
  override def tryCompare(x: SkolemConstructor,y: SkolemConstructor): Option[Int] = {
    if(gt(x,y))
      Some(1)
    else if(lt(x,y))
      Some(-1)
    else if(equiv(x,y))
      Some(0)
    else
      None
  }
}
  
object SkolemConstructors {
  implicit val skolemOrdering = SkolemOrdering
  protected val skolems = new GraphLattice[SkolemConstructor](TopSkolem,BottomSkolem)
  protected val shapes = new HashMap[RecordType,SkolemConstructor]()
  
  def get(shape: RecordType): SkolemConstructor = shapes.get(shape) match {
    case Some(skolem) => skolem
    case None => {
      val result = new SkolemConstructor(shape)
      skolems.add(result)
      shapes.put(shape,result)
      result
    }
  }
}
