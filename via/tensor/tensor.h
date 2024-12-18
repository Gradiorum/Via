#ifndef VIA_TENSOR_TENSOR_H
#define VIA_TENSOR_TENSOR_H

#include <vector>
#include <cstddef>
#include "dtypes.h"

namespace via {

    class Tensor {
    public:
        // Constructor that takes shape and dtype
        Tensor(const std::vector<size_t>& shape, Dtype dtype = Dtype::FLOAT32);

        // Destructor
        ~Tensor();

        // Copy Constructor
        Tensor(const Tensor& other);

        // Copy Assignment Operator
        Tensor& operator=(const Tensor& other);

        // Move Constructor
        Tensor(Tensor&& other) noexcept;

        // Move Assignment Operator
        Tensor& operator=(Tensor&& other) noexcept;

        // Print information about the tensor
        void printInfo() const;

        // Accessors for data
        void* data();
        const void* data() const;

        // Accessors for shape, size, and dtype
        const std::vector<size_t>& shape() const;
        size_t size() const;
        Dtype dtype() const;

    private:
        std::vector<size_t> shape_;    // Shape of the tensor (dimensions)
        size_t size_;                  // Total number of elements
        Dtype dtype_;                  // Data type of the tensor
        size_t element_size_;          // Size in bytes per element
        void* data_;                   // Raw memory for tensor data

        // Disable default constructor if not needed
        Tensor() = delete;
    };
}

#endif // VIA_TENSOR_TENSOR_H
