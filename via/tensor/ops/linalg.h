#ifndef VIA_TENSOR_OPS_LINALG_H
#define VIA_TENSOR_OPS_LINALG_H

#include "../tensor.h"

namespace via {
namespace ops {

    // Matrix multiplication (We are going to use the usual linear algebra method)
    Tensor matmul(const Tensor& A, const Tensor& B);

}
}

#endif // VIA_TENSOR_OPS_LINALG_H
