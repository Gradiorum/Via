#include "tensor.h"
#include "dtypes.h"
#include <stdexcept>
#include <cstring>
#include <iostream>

namespace via {

Tensor::Tensor(const std::vector<size_t>& shape, Dtype dtype)
: shape_(shape), dtype_(dtype), data_(nullptr) {
    size_ = 1;
    for (auto d : shape_) {
        if (d == 0) {
            throw std::runtime_error("Shape dimension cannot be zero");
        }
        size_ *= d;
    }

    element_size_ = dtypeElementSize(dtype_);
    data_ = malloc(size_ * element_size_);
    if (!data_) {
        throw std::runtime_error("Failed to allocate memory for Tensor data");
    }
    std::memset(data_, 0, size_ * element_size_);
}

Tensor::~Tensor() {
    if (data_) {
        free(data_);
        data_ = nullptr;
    }
}

Tensor::Tensor(const Tensor& other)
: shape_(other.shape_), size_(other.size_), dtype_(other.dtype_), element_size_(other.element_size_) {
    data_ = malloc(size_ * element_size_);
    if (!data_) {
        throw std::runtime_error("Failed to allocate memory in copy constructor");
    }
    std::memcpy(data_, other.data_, size_ * element_size_);
}

Tensor& Tensor::operator=(const Tensor& other) {
    if (this == &other) return *this;

    // Free existing data
    if (data_) {
        free(data_);
        data_ = nullptr;
    }

    shape_ = other.shape_;
    size_ = other.size_;
    dtype_ = other.dtype_;
    element_size_ = other.element_size_;

    data_ = malloc(size_ * element_size_);
    if (!data_) {
        throw std::runtime_error("Failed to allocate memory in copy assignment");
    }
    std::memcpy(data_, other.data_, size_ * element_size_);

    return *this;
}

Tensor::Tensor(Tensor&& other) noexcept
: shape_(std::move(other.shape_)), size_(other.size_), dtype_(other.dtype_), element_size_(other.element_size_), data_(other.data_) {
    // Nullify other's data to avoid double free
    other.data_ = nullptr;
    other.size_ = 0;
}

Tensor& Tensor::operator=(Tensor&& other) noexcept {
    if (this == &other) return *this;

    // Free existing data
    if (data_) {
        free(data_);
        data_ = nullptr;
    }

    shape_ = std::move(other.shape_);
    size_ = other.size_;
    dtype_ = other.dtype_;
    element_size_ = other.element_size_;
    data_ = other.data_;

    // Nullify other's data
    other.data_ = nullptr;
    other.size_ = 0;

    return *this;
}

void Tensor::printInfo() const {
    std::cout << "Shape: (";
    for (size_t i = 0; i < shape_.size(); i++) {
        std::cout << shape_[i] << (i+1 < shape_.size()? ", ":"");
    }
    std::cout << "), size=" << size_ << ", dtype=" << dtypeToString(dtype_) << "\n";
}

void* Tensor::data() {
    return data_;
}

const void* Tensor::data() const {
    return data_;
}

const std::vector<size_t>& Tensor::shape() const {
    return shape_;
}

size_t Tensor::size() const {
    return size_;
}

Dtype Tensor::dtype() const {
    return dtype_;
}

} // namespace via
