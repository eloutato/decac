/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.40
 * 
 * This file is not intended to be easily readable and contains a number of 
 * coding conventions designed to improve portability and efficiency. Do not make
 * changes to this file unless you know what you are doing--modify the SWIG 
 * interface file instead. 
 * ----------------------------------------------------------------------------- */

#define SWIGJAVA

/* -----------------------------------------------------------------------------
 *  This section contains generic SWIG labels for method/variable
 *  declarations/attributes, and other compiler dependent labels.
 * ----------------------------------------------------------------------------- */

/* template workaround for compilers that cannot correctly implement the C++ standard */
#ifndef SWIGTEMPLATEDISAMBIGUATOR
# if defined(__SUNPRO_CC) && (__SUNPRO_CC <= 0x560)
#  define SWIGTEMPLATEDISAMBIGUATOR template
# elif defined(__HP_aCC)
/* Needed even with `aCC -AA' when `aCC -V' reports HP ANSI C++ B3910B A.03.55 */
/* If we find a maximum version that requires this, the test would be __HP_aCC <= 35500 for A.03.55 */
#  define SWIGTEMPLATEDISAMBIGUATOR template
# else
#  define SWIGTEMPLATEDISAMBIGUATOR
# endif
#endif

/* inline attribute */
#ifndef SWIGINLINE
# if defined(__cplusplus) || (defined(__GNUC__) && !defined(__STRICT_ANSI__))
#   define SWIGINLINE inline
# else
#   define SWIGINLINE
# endif
#endif

/* attribute recognised by some compilers to avoid 'unused' warnings */
#ifndef SWIGUNUSED
# if defined(__GNUC__)
#   if !(defined(__cplusplus)) || (__GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4))
#     define SWIGUNUSED __attribute__ ((__unused__)) 
#   else
#     define SWIGUNUSED
#   endif
# elif defined(__ICC)
#   define SWIGUNUSED __attribute__ ((__unused__)) 
# else
#   define SWIGUNUSED 
# endif
#endif

#ifndef SWIG_MSC_UNSUPPRESS_4505
# if defined(_MSC_VER)
#   pragma warning(disable : 4505) /* unreferenced local function has been removed */
# endif 
#endif

#ifndef SWIGUNUSEDPARM
# ifdef __cplusplus
#   define SWIGUNUSEDPARM(p)
# else
#   define SWIGUNUSEDPARM(p) p SWIGUNUSED 
# endif
#endif

/* internal SWIG method */
#ifndef SWIGINTERN
# define SWIGINTERN static SWIGUNUSED
#endif

/* internal inline SWIG method */
#ifndef SWIGINTERNINLINE
# define SWIGINTERNINLINE SWIGINTERN SWIGINLINE
#endif

/* exporting methods */
#if (__GNUC__ >= 4) || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4)
#  ifndef GCC_HASCLASSVISIBILITY
#    define GCC_HASCLASSVISIBILITY
#  endif
#endif

#ifndef SWIGEXPORT
# if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
#   if defined(STATIC_LINKED)
#     define SWIGEXPORT
#   else
#     define SWIGEXPORT __declspec(dllexport)
#   endif
# else
#   if defined(__GNUC__) && defined(GCC_HASCLASSVISIBILITY)
#     define SWIGEXPORT __attribute__ ((visibility("default")))
#   else
#     define SWIGEXPORT
#   endif
# endif
#endif

/* calling conventions for Windows */
#ifndef SWIGSTDCALL
# if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
#   define SWIGSTDCALL __stdcall
# else
#   define SWIGSTDCALL
# endif 
#endif

/* Deal with Microsoft's attempt at deprecating C standard runtime functions */
#if !defined(SWIG_NO_CRT_SECURE_NO_DEPRECATE) && defined(_MSC_VER) && !defined(_CRT_SECURE_NO_DEPRECATE)
# define _CRT_SECURE_NO_DEPRECATE
#endif

/* Deal with Microsoft's attempt at deprecating methods in the standard C++ library */
#if !defined(SWIG_NO_SCL_SECURE_NO_DEPRECATE) && defined(_MSC_VER) && !defined(_SCL_SECURE_NO_DEPRECATE)
# define _SCL_SECURE_NO_DEPRECATE
#endif



/* Fix for jlong on some versions of gcc on Windows */
#if defined(__GNUC__) && !defined(__INTEL_COMPILER)
  typedef long long __int64;
#endif

/* Fix for jlong on 64-bit x86 Solaris */
#if defined(__x86_64)
# ifdef _LP64
#   undef _LP64
# endif
#endif

#include <jni.h>
#include <stdlib.h>
#include <string.h>


/* Support for throwing Java exceptions */
typedef enum {
  SWIG_JavaOutOfMemoryError = 1, 
  SWIG_JavaIOException, 
  SWIG_JavaRuntimeException, 
  SWIG_JavaIndexOutOfBoundsException,
  SWIG_JavaArithmeticException,
  SWIG_JavaIllegalArgumentException,
  SWIG_JavaNullPointerException,
  SWIG_JavaDirectorPureVirtual,
  SWIG_JavaUnknownError
} SWIG_JavaExceptionCodes;

typedef struct {
  SWIG_JavaExceptionCodes code;
  const char *java_exception;
} SWIG_JavaExceptions_t;


static void SWIGUNUSED SWIG_JavaThrowException(JNIEnv *jenv, SWIG_JavaExceptionCodes code, const char *msg) {
  jclass excep;
  static const SWIG_JavaExceptions_t java_exceptions[] = {
    { SWIG_JavaOutOfMemoryError, "java/lang/OutOfMemoryError" },
    { SWIG_JavaIOException, "java/io/IOException" },
    { SWIG_JavaRuntimeException, "java/lang/RuntimeException" },
    { SWIG_JavaIndexOutOfBoundsException, "java/lang/IndexOutOfBoundsException" },
    { SWIG_JavaArithmeticException, "java/lang/ArithmeticException" },
    { SWIG_JavaIllegalArgumentException, "java/lang/IllegalArgumentException" },
    { SWIG_JavaNullPointerException, "java/lang/NullPointerException" },
    { SWIG_JavaDirectorPureVirtual, "java/lang/RuntimeException" },
    { SWIG_JavaUnknownError,  "java/lang/UnknownError" },
    { (SWIG_JavaExceptionCodes)0,  "java/lang/UnknownError" }
  };
  const SWIG_JavaExceptions_t *except_ptr = java_exceptions;

  while (except_ptr->code != code && except_ptr->code)
    except_ptr++;

  (*jenv)->ExceptionClear(jenv);
  excep = (*jenv)->FindClass(jenv, except_ptr->java_exception);
  if (excep)
    (*jenv)->ThrowNew(jenv, excep, msg);
}


/* Contract support */

#define SWIG_contract_assert(nullreturn, expr, msg) if (!(expr)) {SWIG_JavaThrowException(jenv, SWIG_JavaIllegalArgumentException, msg); return nullreturn; } else


#include <llvm-c/ExecutionEngine.h>


static LLVMValueRef *new_LLVMValueRefArray(int nelements) { 
  return (LLVMValueRef *) calloc(nelements,sizeof(LLVMValueRef)); 
}

static void delete_LLVMValueRefArray(LLVMValueRef *ary) { 
  free(ary); 
}

static LLVMValueRef LLVMValueRefArray_getitem(LLVMValueRef *ary, int index) {
    return ary[index];
}
static void LLVMValueRefArray_setitem(LLVMValueRef *ary, int index, LLVMValueRef value) {
    ary[index] = value;
}


#ifdef __cplusplus
extern "C" {
#endif

SWIGEXPORT jlong JNICALL Java_jllvm_llvm_ExecutionEngineJNI_new_1LLVMValueRefArray(JNIEnv *jenv, jclass jcls, jint jarg1) {
  jlong jresult = 0 ;
  int arg1 ;
  LLVMValueRef *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = (int)jarg1; 
  result = (LLVMValueRef *)new_LLVMValueRefArray(arg1);
  *(LLVMValueRef **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_jllvm_llvm_ExecutionEngineJNI_delete_1LLVMValueRefArray(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  LLVMValueRef *arg1 = (LLVMValueRef *) 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(LLVMValueRef **)&jarg1; 
  delete_LLVMValueRefArray(arg1);
}


SWIGEXPORT jlong JNICALL Java_jllvm_llvm_ExecutionEngineJNI_LLVMValueRefArray_1getitem(JNIEnv *jenv, jclass jcls, jlong jarg1, jint jarg2) {
  jlong jresult = 0 ;
  LLVMValueRef *arg1 = (LLVMValueRef *) 0 ;
  int arg2 ;
  LLVMValueRef result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(LLVMValueRef **)&jarg1; 
  arg2 = (int)jarg2; 
  result = LLVMValueRefArray_getitem(arg1,arg2);
  {
    LLVMValueRef * resultptr = (LLVMValueRef *) malloc(sizeof(LLVMValueRef));
    memmove(resultptr, &result, sizeof(LLVMValueRef));
    *(LLVMValueRef **)&jresult = resultptr;
  }
  return jresult;
}


SWIGEXPORT void JNICALL Java_jllvm_llvm_ExecutionEngineJNI_LLVMValueRefArray_1setitem(JNIEnv *jenv, jclass jcls, jlong jarg1, jint jarg2, jlong jarg3) {
  LLVMValueRef *arg1 = (LLVMValueRef *) 0 ;
  int arg2 ;
  LLVMValueRef arg3 ;
  LLVMValueRef *argp3 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(LLVMValueRef **)&jarg1; 
  arg2 = (int)jarg2; 
  argp3 = *(LLVMValueRef **)&jarg3; 
  if (!argp3) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "Attempt to dereference null LLVMValueRef");
    return ;
  }
  arg3 = *argp3; 
  LLVMValueRefArray_setitem(arg1,arg2,arg3);
}


SWIGEXPORT void JNICALL Java_jllvm_llvm_ExecutionEngineJNI_LLVMLinkInJIT(JNIEnv *jenv, jclass jcls) {
  (void)jenv;
  (void)jcls;
  LLVMLinkInJIT();
}


SWIGEXPORT void JNICALL Java_jllvm_llvm_ExecutionEngineJNI_LLVMLinkInInterpreter(JNIEnv *jenv, jclass jcls) {
  (void)jenv;
  (void)jcls;
  LLVMLinkInInterpreter();
}


SWIGEXPORT jlong JNICALL Java_jllvm_llvm_ExecutionEngineJNI_LLVMCreateGenericValueOfInt(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg2, jlong jarg3) {
  jlong jresult = 0 ;
  LLVMTypeRef arg1 ;
  unsigned long long arg2 ;
  LLVMBool arg3 ;
  LLVMTypeRef *argp1 ;
  LLVMBool *argp3 ;
  LLVMGenericValueRef result;
  
  (void)jenv;
  (void)jcls;
  argp1 = *(LLVMTypeRef **)&jarg1; 
  if (!argp1) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "Attempt to dereference null LLVMTypeRef");
    return 0;
  }
  arg1 = *argp1; 
  {
    jclass clazz;
    jmethodID mid;
    jbyteArray ba;
    jbyte* bae;
    jsize sz;
    int i;
    
    if (!jarg2) {
      SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "BigInteger null");
      return 0;
    }
    clazz = (*jenv)->GetObjectClass(jenv, jarg2);
    mid = (*jenv)->GetMethodID(jenv, clazz, "toByteArray", "()[B");
    ba = (jbyteArray)(*jenv)->CallObjectMethod(jenv, jarg2, mid);
    bae = (*jenv)->GetByteArrayElements(jenv, ba, 0);
    sz = (*jenv)->GetArrayLength(jenv, ba);
    arg2 = 0;
    for(i=0; i<sz; i++) {
      arg2 = (arg2 << 8) | (unsigned long long)(unsigned char)bae[i];
    }
    (*jenv)->ReleaseByteArrayElements(jenv, ba, bae, 0);
  }
  argp3 = *(LLVMBool **)&jarg3; 
  if (!argp3) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "Attempt to dereference null LLVMBool");
    return 0;
  }
  arg3 = *argp3; 
  result = (LLVMGenericValueRef)LLVMCreateGenericValueOfInt(arg1,arg2,arg3);
  *(LLVMGenericValueRef *)&jresult = result; 
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_jllvm_llvm_ExecutionEngineJNI_LLVMCreateGenericValueOfPointer(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  jlong jresult = 0 ;
  void *arg1 = (void *) 0 ;
  LLVMGenericValueRef result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(void **)&jarg1; 
  result = (LLVMGenericValueRef)LLVMCreateGenericValueOfPointer(arg1);
  *(LLVMGenericValueRef *)&jresult = result; 
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_jllvm_llvm_ExecutionEngineJNI_LLVMCreateGenericValueOfFloat(JNIEnv *jenv, jclass jcls, jlong jarg1, jdouble jarg2) {
  jlong jresult = 0 ;
  LLVMTypeRef arg1 ;
  double arg2 ;
  LLVMTypeRef *argp1 ;
  LLVMGenericValueRef result;
  
  (void)jenv;
  (void)jcls;
  argp1 = *(LLVMTypeRef **)&jarg1; 
  if (!argp1) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "Attempt to dereference null LLVMTypeRef");
    return 0;
  }
  arg1 = *argp1; 
  arg2 = (double)jarg2; 
  result = (LLVMGenericValueRef)LLVMCreateGenericValueOfFloat(arg1,arg2);
  *(LLVMGenericValueRef *)&jresult = result; 
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_jllvm_llvm_ExecutionEngineJNI_LLVMGenericValueIntWidth(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  jlong jresult = 0 ;
  LLVMGenericValueRef arg1 = (LLVMGenericValueRef) 0 ;
  unsigned int result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(LLVMGenericValueRef *)&jarg1; 
  result = (unsigned int)LLVMGenericValueIntWidth(arg1);
  jresult = (jlong)result; 
  return jresult;
}


SWIGEXPORT jobject JNICALL Java_jllvm_llvm_ExecutionEngineJNI_LLVMGenericValueToInt(JNIEnv *jenv, jclass jcls, jlong jarg1, jlong jarg2) {
  jobject jresult = 0 ;
  LLVMGenericValueRef arg1 = (LLVMGenericValueRef) 0 ;
  LLVMBool arg2 ;
  LLVMBool *argp2 ;
  unsigned long long result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(LLVMGenericValueRef *)&jarg1; 
  argp2 = *(LLVMBool **)&jarg2; 
  if (!argp2) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "Attempt to dereference null LLVMBool");
    return 0;
  }
  arg2 = *argp2; 
  result = (unsigned long long)LLVMGenericValueToInt(arg1,arg2);
  {
    jbyteArray ba = (*jenv)->NewByteArray(jenv, 9);
    jbyte* bae = (*jenv)->GetByteArrayElements(jenv, ba, 0);
    jclass clazz = (*jenv)->FindClass(jenv, "java/math/BigInteger");
    jmethodID mid = (*jenv)->GetMethodID(jenv, clazz, "<init>", "([B)V");
    jobject bigint;
    int i;
    
    bae[0] = 0;
    for(i=1; i<9; i++ ) {
      bae[i] = (jbyte)(result>>8*(8-i));
    }
    
    (*jenv)->ReleaseByteArrayElements(jenv, ba, bae, 0);
    bigint = (*jenv)->NewObject(jenv, clazz, mid, ba);
    jresult = bigint;
  }
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_jllvm_llvm_ExecutionEngineJNI_LLVMGenericValueToPointer(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  jlong jresult = 0 ;
  LLVMGenericValueRef arg1 = (LLVMGenericValueRef) 0 ;
  void *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(LLVMGenericValueRef *)&jarg1; 
  result = (void *)LLVMGenericValueToPointer(arg1);
  *(void **)&jresult = result; 
  return jresult;
}


SWIGEXPORT jdouble JNICALL Java_jllvm_llvm_ExecutionEngineJNI_LLVMGenericValueToFloat(JNIEnv *jenv, jclass jcls, jlong jarg1, jlong jarg2) {
  jdouble jresult = 0 ;
  LLVMTypeRef arg1 ;
  LLVMGenericValueRef arg2 = (LLVMGenericValueRef) 0 ;
  LLVMTypeRef *argp1 ;
  double result;
  
  (void)jenv;
  (void)jcls;
  argp1 = *(LLVMTypeRef **)&jarg1; 
  if (!argp1) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "Attempt to dereference null LLVMTypeRef");
    return 0;
  }
  arg1 = *argp1; 
  arg2 = *(LLVMGenericValueRef *)&jarg2; 
  result = (double)LLVMGenericValueToFloat(arg1,arg2);
  jresult = (jdouble)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_jllvm_llvm_ExecutionEngineJNI_LLVMDisposeGenericValue(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  LLVMGenericValueRef arg1 = (LLVMGenericValueRef) 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(LLVMGenericValueRef *)&jarg1; 
  LLVMDisposeGenericValue(arg1);
}


SWIGEXPORT jlong JNICALL Java_jllvm_llvm_ExecutionEngineJNI_LLVMCreateExecutionEngineForModule(JNIEnv *jenv, jclass jcls, jlong jarg1, jlong jarg2, jlong jarg3) {
  jlong jresult = 0 ;
  LLVMExecutionEngineRef *arg1 = (LLVMExecutionEngineRef *) 0 ;
  LLVMModuleRef arg2 ;
  char **arg3 = (char **) 0 ;
  LLVMModuleRef *argp2 ;
  LLVMBool result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(LLVMExecutionEngineRef **)&jarg1; 
  argp2 = *(LLVMModuleRef **)&jarg2; 
  if (!argp2) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "Attempt to dereference null LLVMModuleRef");
    return 0;
  }
  arg2 = *argp2; 
  arg3 = *(char ***)&jarg3; 
  result = LLVMCreateExecutionEngineForModule(arg1,arg2,arg3);
  {
    LLVMBool * resultptr = (LLVMBool *) malloc(sizeof(LLVMBool));
    memmove(resultptr, &result, sizeof(LLVMBool));
    *(LLVMBool **)&jresult = resultptr;
  }
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_jllvm_llvm_ExecutionEngineJNI_LLVMCreateInterpreterForModule(JNIEnv *jenv, jclass jcls, jlong jarg1, jlong jarg2, jlong jarg3) {
  jlong jresult = 0 ;
  LLVMExecutionEngineRef *arg1 = (LLVMExecutionEngineRef *) 0 ;
  LLVMModuleRef arg2 ;
  char **arg3 = (char **) 0 ;
  LLVMModuleRef *argp2 ;
  LLVMBool result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(LLVMExecutionEngineRef **)&jarg1; 
  argp2 = *(LLVMModuleRef **)&jarg2; 
  if (!argp2) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "Attempt to dereference null LLVMModuleRef");
    return 0;
  }
  arg2 = *argp2; 
  arg3 = *(char ***)&jarg3; 
  result = LLVMCreateInterpreterForModule(arg1,arg2,arg3);
  {
    LLVMBool * resultptr = (LLVMBool *) malloc(sizeof(LLVMBool));
    memmove(resultptr, &result, sizeof(LLVMBool));
    *(LLVMBool **)&jresult = resultptr;
  }
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_jllvm_llvm_ExecutionEngineJNI_LLVMCreateJITCompilerForModule(JNIEnv *jenv, jclass jcls, jlong jarg1, jlong jarg2, jlong jarg3, jlong jarg4) {
  jlong jresult = 0 ;
  LLVMExecutionEngineRef *arg1 = (LLVMExecutionEngineRef *) 0 ;
  LLVMModuleRef arg2 ;
  unsigned int arg3 ;
  char **arg4 = (char **) 0 ;
  LLVMModuleRef *argp2 ;
  LLVMBool result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(LLVMExecutionEngineRef **)&jarg1; 
  argp2 = *(LLVMModuleRef **)&jarg2; 
  if (!argp2) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "Attempt to dereference null LLVMModuleRef");
    return 0;
  }
  arg2 = *argp2; 
  arg3 = (unsigned int)jarg3; 
  arg4 = *(char ***)&jarg4; 
  result = LLVMCreateJITCompilerForModule(arg1,arg2,arg3,arg4);
  {
    LLVMBool * resultptr = (LLVMBool *) malloc(sizeof(LLVMBool));
    memmove(resultptr, &result, sizeof(LLVMBool));
    *(LLVMBool **)&jresult = resultptr;
  }
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_jllvm_llvm_ExecutionEngineJNI_LLVMCreateExecutionEngine(JNIEnv *jenv, jclass jcls, jlong jarg1, jlong jarg2, jlong jarg3) {
  jlong jresult = 0 ;
  LLVMExecutionEngineRef *arg1 = (LLVMExecutionEngineRef *) 0 ;
  LLVMModuleProviderRef arg2 ;
  char **arg3 = (char **) 0 ;
  LLVMModuleProviderRef *argp2 ;
  LLVMBool result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(LLVMExecutionEngineRef **)&jarg1; 
  argp2 = *(LLVMModuleProviderRef **)&jarg2; 
  if (!argp2) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "Attempt to dereference null LLVMModuleProviderRef");
    return 0;
  }
  arg2 = *argp2; 
  arg3 = *(char ***)&jarg3; 
  result = LLVMCreateExecutionEngine(arg1,arg2,arg3);
  {
    LLVMBool * resultptr = (LLVMBool *) malloc(sizeof(LLVMBool));
    memmove(resultptr, &result, sizeof(LLVMBool));
    *(LLVMBool **)&jresult = resultptr;
  }
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_jllvm_llvm_ExecutionEngineJNI_LLVMCreateInterpreter(JNIEnv *jenv, jclass jcls, jlong jarg1, jlong jarg2, jlong jarg3) {
  jlong jresult = 0 ;
  LLVMExecutionEngineRef *arg1 = (LLVMExecutionEngineRef *) 0 ;
  LLVMModuleProviderRef arg2 ;
  char **arg3 = (char **) 0 ;
  LLVMModuleProviderRef *argp2 ;
  LLVMBool result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(LLVMExecutionEngineRef **)&jarg1; 
  argp2 = *(LLVMModuleProviderRef **)&jarg2; 
  if (!argp2) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "Attempt to dereference null LLVMModuleProviderRef");
    return 0;
  }
  arg2 = *argp2; 
  arg3 = *(char ***)&jarg3; 
  result = LLVMCreateInterpreter(arg1,arg2,arg3);
  {
    LLVMBool * resultptr = (LLVMBool *) malloc(sizeof(LLVMBool));
    memmove(resultptr, &result, sizeof(LLVMBool));
    *(LLVMBool **)&jresult = resultptr;
  }
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_jllvm_llvm_ExecutionEngineJNI_LLVMCreateJITCompiler(JNIEnv *jenv, jclass jcls, jlong jarg1, jlong jarg2, jlong jarg3, jlong jarg4) {
  jlong jresult = 0 ;
  LLVMExecutionEngineRef *arg1 = (LLVMExecutionEngineRef *) 0 ;
  LLVMModuleProviderRef arg2 ;
  unsigned int arg3 ;
  char **arg4 = (char **) 0 ;
  LLVMModuleProviderRef *argp2 ;
  LLVMBool result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(LLVMExecutionEngineRef **)&jarg1; 
  argp2 = *(LLVMModuleProviderRef **)&jarg2; 
  if (!argp2) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "Attempt to dereference null LLVMModuleProviderRef");
    return 0;
  }
  arg2 = *argp2; 
  arg3 = (unsigned int)jarg3; 
  arg4 = *(char ***)&jarg4; 
  result = LLVMCreateJITCompiler(arg1,arg2,arg3,arg4);
  {
    LLVMBool * resultptr = (LLVMBool *) malloc(sizeof(LLVMBool));
    memmove(resultptr, &result, sizeof(LLVMBool));
    *(LLVMBool **)&jresult = resultptr;
  }
  return jresult;
}


SWIGEXPORT void JNICALL Java_jllvm_llvm_ExecutionEngineJNI_LLVMDisposeExecutionEngine(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  LLVMExecutionEngineRef arg1 = (LLVMExecutionEngineRef) 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(LLVMExecutionEngineRef *)&jarg1; 
  LLVMDisposeExecutionEngine(arg1);
}


SWIGEXPORT void JNICALL Java_jllvm_llvm_ExecutionEngineJNI_LLVMRunStaticConstructors(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  LLVMExecutionEngineRef arg1 = (LLVMExecutionEngineRef) 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(LLVMExecutionEngineRef *)&jarg1; 
  LLVMRunStaticConstructors(arg1);
}


SWIGEXPORT void JNICALL Java_jllvm_llvm_ExecutionEngineJNI_LLVMRunStaticDestructors(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  LLVMExecutionEngineRef arg1 = (LLVMExecutionEngineRef) 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(LLVMExecutionEngineRef *)&jarg1; 
  LLVMRunStaticDestructors(arg1);
}


SWIGEXPORT jint JNICALL Java_jllvm_llvm_ExecutionEngineJNI_LLVMRunFunctionAsMain(JNIEnv *jenv, jclass jcls, jlong jarg1, jlong jarg2, jlong jarg3, jlong jarg4, jlong jarg5) {
  jint jresult = 0 ;
  LLVMExecutionEngineRef arg1 = (LLVMExecutionEngineRef) 0 ;
  LLVMValueRef arg2 ;
  unsigned int arg3 ;
  char **arg4 = (char **) 0 ;
  char **arg5 = (char **) 0 ;
  LLVMValueRef *argp2 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(LLVMExecutionEngineRef *)&jarg1; 
  argp2 = *(LLVMValueRef **)&jarg2; 
  if (!argp2) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "Attempt to dereference null LLVMValueRef");
    return 0;
  }
  arg2 = *argp2; 
  arg3 = (unsigned int)jarg3; 
  arg4 = *(char ***)&jarg4; 
  arg5 = *(char ***)&jarg5; 
  result = (int)LLVMRunFunctionAsMain(arg1,arg2,arg3,(char const *const *)arg4,(char const *const *)arg5);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_jllvm_llvm_ExecutionEngineJNI_LLVMRunFunction(JNIEnv *jenv, jclass jcls, jlong jarg1, jlong jarg2, jlong jarg3, jlong jarg4) {
  jlong jresult = 0 ;
  LLVMExecutionEngineRef arg1 = (LLVMExecutionEngineRef) 0 ;
  LLVMValueRef arg2 ;
  unsigned int arg3 ;
  LLVMGenericValueRef *arg4 = (LLVMGenericValueRef *) 0 ;
  LLVMValueRef *argp2 ;
  LLVMGenericValueRef result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(LLVMExecutionEngineRef *)&jarg1; 
  argp2 = *(LLVMValueRef **)&jarg2; 
  if (!argp2) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "Attempt to dereference null LLVMValueRef");
    return 0;
  }
  arg2 = *argp2; 
  arg3 = (unsigned int)jarg3; 
  arg4 = *(LLVMGenericValueRef **)&jarg4; 
  result = (LLVMGenericValueRef)LLVMRunFunction(arg1,arg2,arg3,arg4);
  *(LLVMGenericValueRef *)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_jllvm_llvm_ExecutionEngineJNI_LLVMFreeMachineCodeForFunction(JNIEnv *jenv, jclass jcls, jlong jarg1, jlong jarg2) {
  LLVMExecutionEngineRef arg1 = (LLVMExecutionEngineRef) 0 ;
  LLVMValueRef arg2 ;
  LLVMValueRef *argp2 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(LLVMExecutionEngineRef *)&jarg1; 
  argp2 = *(LLVMValueRef **)&jarg2; 
  if (!argp2) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "Attempt to dereference null LLVMValueRef");
    return ;
  }
  arg2 = *argp2; 
  LLVMFreeMachineCodeForFunction(arg1,arg2);
}


SWIGEXPORT void JNICALL Java_jllvm_llvm_ExecutionEngineJNI_LLVMAddModule(JNIEnv *jenv, jclass jcls, jlong jarg1, jlong jarg2) {
  LLVMExecutionEngineRef arg1 = (LLVMExecutionEngineRef) 0 ;
  LLVMModuleRef arg2 ;
  LLVMModuleRef *argp2 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(LLVMExecutionEngineRef *)&jarg1; 
  argp2 = *(LLVMModuleRef **)&jarg2; 
  if (!argp2) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "Attempt to dereference null LLVMModuleRef");
    return ;
  }
  arg2 = *argp2; 
  LLVMAddModule(arg1,arg2);
}


SWIGEXPORT void JNICALL Java_jllvm_llvm_ExecutionEngineJNI_LLVMAddModuleProvider(JNIEnv *jenv, jclass jcls, jlong jarg1, jlong jarg2) {
  LLVMExecutionEngineRef arg1 = (LLVMExecutionEngineRef) 0 ;
  LLVMModuleProviderRef arg2 ;
  LLVMModuleProviderRef *argp2 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(LLVMExecutionEngineRef *)&jarg1; 
  argp2 = *(LLVMModuleProviderRef **)&jarg2; 
  if (!argp2) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "Attempt to dereference null LLVMModuleProviderRef");
    return ;
  }
  arg2 = *argp2; 
  LLVMAddModuleProvider(arg1,arg2);
}


SWIGEXPORT jlong JNICALL Java_jllvm_llvm_ExecutionEngineJNI_LLVMRemoveModule(JNIEnv *jenv, jclass jcls, jlong jarg1, jlong jarg2, jlong jarg3, jlong jarg4) {
  jlong jresult = 0 ;
  LLVMExecutionEngineRef arg1 = (LLVMExecutionEngineRef) 0 ;
  LLVMModuleRef arg2 ;
  LLVMModuleRef *arg3 = (LLVMModuleRef *) 0 ;
  char **arg4 = (char **) 0 ;
  LLVMModuleRef *argp2 ;
  LLVMBool result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(LLVMExecutionEngineRef *)&jarg1; 
  argp2 = *(LLVMModuleRef **)&jarg2; 
  if (!argp2) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "Attempt to dereference null LLVMModuleRef");
    return 0;
  }
  arg2 = *argp2; 
  arg3 = *(LLVMModuleRef **)&jarg3; 
  arg4 = *(char ***)&jarg4; 
  result = LLVMRemoveModule(arg1,arg2,arg3,arg4);
  {
    LLVMBool * resultptr = (LLVMBool *) malloc(sizeof(LLVMBool));
    memmove(resultptr, &result, sizeof(LLVMBool));
    *(LLVMBool **)&jresult = resultptr;
  }
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_jllvm_llvm_ExecutionEngineJNI_LLVMRemoveModuleProvider(JNIEnv *jenv, jclass jcls, jlong jarg1, jlong jarg2, jlong jarg3, jlong jarg4) {
  jlong jresult = 0 ;
  LLVMExecutionEngineRef arg1 = (LLVMExecutionEngineRef) 0 ;
  LLVMModuleProviderRef arg2 ;
  LLVMModuleRef *arg3 = (LLVMModuleRef *) 0 ;
  char **arg4 = (char **) 0 ;
  LLVMModuleProviderRef *argp2 ;
  LLVMBool result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(LLVMExecutionEngineRef *)&jarg1; 
  argp2 = *(LLVMModuleProviderRef **)&jarg2; 
  if (!argp2) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "Attempt to dereference null LLVMModuleProviderRef");
    return 0;
  }
  arg2 = *argp2; 
  arg3 = *(LLVMModuleRef **)&jarg3; 
  arg4 = *(char ***)&jarg4; 
  result = LLVMRemoveModuleProvider(arg1,arg2,arg3,arg4);
  {
    LLVMBool * resultptr = (LLVMBool *) malloc(sizeof(LLVMBool));
    memmove(resultptr, &result, sizeof(LLVMBool));
    *(LLVMBool **)&jresult = resultptr;
  }
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_jllvm_llvm_ExecutionEngineJNI_LLVMFindFunction(JNIEnv *jenv, jclass jcls, jlong jarg1, jstring jarg2, jlong jarg3) {
  jlong jresult = 0 ;
  LLVMExecutionEngineRef arg1 = (LLVMExecutionEngineRef) 0 ;
  char *arg2 = (char *) 0 ;
  LLVMValueRef *arg3 = (LLVMValueRef *) 0 ;
  LLVMBool result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(LLVMExecutionEngineRef *)&jarg1; 
  arg2 = 0;
  if (jarg2) {
    arg2 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg2, 0);
    if (!arg2) return 0;
  }
  arg3 = *(LLVMValueRef **)&jarg3; 
  result = LLVMFindFunction(arg1,(char const *)arg2,arg3);
  {
    LLVMBool * resultptr = (LLVMBool *) malloc(sizeof(LLVMBool));
    memmove(resultptr, &result, sizeof(LLVMBool));
    *(LLVMBool **)&jresult = resultptr;
  }
  if (arg2) (*jenv)->ReleaseStringUTFChars(jenv, jarg2, (const char *)arg2);
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_jllvm_llvm_ExecutionEngineJNI_LLVMGetExecutionEngineTargetData(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  jlong jresult = 0 ;
  LLVMExecutionEngineRef arg1 = (LLVMExecutionEngineRef) 0 ;
  LLVMTargetDataRef result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(LLVMExecutionEngineRef *)&jarg1; 
  result = LLVMGetExecutionEngineTargetData(arg1);
  {
    LLVMTargetDataRef * resultptr = (LLVMTargetDataRef *) malloc(sizeof(LLVMTargetDataRef));
    memmove(resultptr, &result, sizeof(LLVMTargetDataRef));
    *(LLVMTargetDataRef **)&jresult = resultptr;
  }
  return jresult;
}


SWIGEXPORT void JNICALL Java_jllvm_llvm_ExecutionEngineJNI_LLVMAddGlobalMapping(JNIEnv *jenv, jclass jcls, jlong jarg1, jlong jarg2, jlong jarg3) {
  LLVMExecutionEngineRef arg1 = (LLVMExecutionEngineRef) 0 ;
  LLVMValueRef arg2 ;
  void *arg3 = (void *) 0 ;
  LLVMValueRef *argp2 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(LLVMExecutionEngineRef *)&jarg1; 
  argp2 = *(LLVMValueRef **)&jarg2; 
  if (!argp2) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "Attempt to dereference null LLVMValueRef");
    return ;
  }
  arg2 = *argp2; 
  arg3 = *(void **)&jarg3; 
  LLVMAddGlobalMapping(arg1,arg2,arg3);
}


SWIGEXPORT jlong JNICALL Java_jllvm_llvm_ExecutionEngineJNI_LLVMGetPointerToGlobal(JNIEnv *jenv, jclass jcls, jlong jarg1, jlong jarg2) {
  jlong jresult = 0 ;
  LLVMExecutionEngineRef arg1 = (LLVMExecutionEngineRef) 0 ;
  LLVMValueRef arg2 ;
  LLVMValueRef *argp2 ;
  void *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(LLVMExecutionEngineRef *)&jarg1; 
  argp2 = *(LLVMValueRef **)&jarg2; 
  if (!argp2) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "Attempt to dereference null LLVMValueRef");
    return 0;
  }
  arg2 = *argp2; 
  result = (void *)LLVMGetPointerToGlobal(arg1,arg2);
  *(void **)&jresult = result; 
  return jresult;
}


#ifdef __cplusplus
}
#endif

