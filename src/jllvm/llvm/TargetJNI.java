/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.40
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package jllvm.llvm;

class TargetJNI {
  public final static native void LLVMInitializeAllTargetInfos();
  public final static native void LLVMInitializeAllTargets();
  public final static native long LLVMInitializeNativeTarget();
  public final static native long LLVMCreateTargetData(String jarg1);
  public final static native void LLVMAddTargetData(long jarg1, long jarg2);
  public final static native String LLVMCopyStringRepOfTargetData(long jarg1);
  public final static native int LLVMByteOrder(long jarg1);
  public final static native long LLVMPointerSize(long jarg1);
  public final static native long LLVMIntPtrType(long jarg1);
  public final static native java.math.BigInteger LLVMSizeOfTypeInBits(long jarg1, long jarg2);
  public final static native java.math.BigInteger LLVMStoreSizeOfType(long jarg1, long jarg2);
  public final static native java.math.BigInteger LLVMABISizeOfType(long jarg1, long jarg2);
  public final static native long LLVMABIAlignmentOfType(long jarg1, long jarg2);
  public final static native long LLVMCallFrameAlignmentOfType(long jarg1, long jarg2);
  public final static native long LLVMPreferredAlignmentOfType(long jarg1, long jarg2);
  public final static native long LLVMPreferredAlignmentOfGlobal(long jarg1, long jarg2);
  public final static native long LLVMElementAtOffset(long jarg1, long jarg2, java.math.BigInteger jarg3);
  public final static native java.math.BigInteger LLVMOffsetOfElement(long jarg1, long jarg2, long jarg3);
  public final static native void LLVMInvalidateStructLayout(long jarg1, long jarg2);
  public final static native void LLVMDisposeTargetData(long jarg1);
}
