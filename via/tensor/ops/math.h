#ifndef VIA_TENSOR_OPS_MATH_H
#define VIA_TENSOR_OPS_MATH_H

#include "../tensor.h" // Include the tensor definition
// If you want to keep includes minimal, consider forward declarations

namespace via {
namespace ops {

    // Element-wise addition of two tensors
    // For now, assume they have the same shape and dtype
    Tensor add(const Tensor& A, const Tensor& B);

    // Element-wise subtraction
    Tensor sub(const Tensor& A, const Tensor& B);

    // Element-wise multiplication
    Tensor mul(const Tensor& A, const Tensor& B);

    // (Later) broadcasting support can be added

}
}

#endif // VIA_TENSOR_OPS_MATH_H
