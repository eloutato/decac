/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.40
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package jllvm.llvm;

public class LinkTimeOptimizer {
  public static SWIGTYPE_p_void llvm_create_optimizer() {
    long cPtr = LinkTimeOptimizerJNI.llvm_create_optimizer();
    return (cPtr == 0) ? null : new SWIGTYPE_p_void(cPtr, false);
  }

  public static void llvm_destroy_optimizer(SWIGTYPE_p_void lto) {
    LinkTimeOptimizerJNI.llvm_destroy_optimizer(SWIGTYPE_p_void.getCPtr(lto));
  }

  public static llvm_lto_status_t llvm_read_object_file(SWIGTYPE_p_void lto, String input_filename) {
    return llvm_lto_status_t.swigToEnum(LinkTimeOptimizerJNI.llvm_read_object_file(SWIGTYPE_p_void.getCPtr(lto), input_filename));
  }

  public static llvm_lto_status_t llvm_optimize_modules(SWIGTYPE_p_void lto, String output_filename) {
    return llvm_lto_status_t.swigToEnum(LinkTimeOptimizerJNI.llvm_optimize_modules(SWIGTYPE_p_void.getCPtr(lto), output_filename));
  }

}
