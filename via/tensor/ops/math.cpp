#include "math.h"
#include "stdexcept"
#include "cstring"
#include "exceptions.h"

namespace via{
namespace ops{

Tensor add(const Tensor& A, const Tensor& B){
    if (A.shape() != B.shape()) {
    throw via::TensorShapeError("Shape mismatch between tensors A and B.");
    }
    if (A.dtype() != B.dtype()) {
        throw via::DtypeError("Dtype mismatch between tensors A and B.");
    }
    
    Tensor C(A.shape(), A.dtype());
    const float* a_data = (const float*)A.data();
    const float* b_data = (const float*)B.data();
    float* c_data = (float*)C.data();

    for (size_t i = 0; i< A.size(); i++){
        c_data[i] = a_data[i]+ b_data[i];
    }
    return C;
}
Tensor sub(const Tensor& A, const Tensor& B){
    if (A.shape() != B.shape()) {
        throw via::TensorShapeError("Shape mismatch between tensors A and B.");
    }
    if (A.dtype() != B.dtype()){
        throw via::DtypeError("Dtype mismatch between tensors A and B.");

    }
    Tensor C(A.shape(), A.dtype());
    const float* a_data = (const float*)A.data();
    const float* b_data = (const float*)B.data();
    float* c_data = (float*)C.data();
    for (size_t i = 0; i< A.size(); i++){
        c_data[i] = a_data[i] - b_data[i];

    }
    return C;
}
Tensor mul(const Tensor&A, const Tensor&B){
    if (A.shape() != B.shape()){
        throw via::TensorShapeError("Shape mismatch between tensor A and B.");
    }
    if (A.dtype() != B.dtype()){
        throw via::DtypeError("Dtype mismatch between tensors A and B.");
    }

    Tensor C(A.shape(), A.dtype());
    const float* a_data = (const float*)A.data();
    const float* b_data = (const float*)B.data();
    float* c_data = (float*)C.data();

    for (size_t i = 0; i < A.size(); i++){
        c_data[i] = a_data[i] * b_data[i];

    }
    return C;

}
Tensor div(const Tensor&A, const Tensor&B){
    if (A.shape() != B.shape()){
        throw via::TensorShapeError("Shape mismatch between tensor A and B.");
    }
    if (A.dtype() != B.dtype()){
        throw via::DtypeError("Dtype mismatch between tensors A and B.");
    }

    Tensor C(A.shape(), A.dtype());
    const float* a_data = (const float*)A.data();
    const float* b_data = (const float*)B.data();
    float* c_data = (float*)C.data();

    for (size_t i = 0; i < A.size(); i++){
        c_data[i] = a_data[i] / b_data[i];

    }
    return C;

}
}
}