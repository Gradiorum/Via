#include <iostream>
#include <vector>
#include <stdexcept>
#include <cstring> // for memset
#include <cstdint> // for fixed width ints

enum class Dtype {
    FLOAT16,
    FLOAT32,
    FLOAT64,
    INT32,
    BFLOAT16
    // Add more as needed
};

class Tensor {
public:
    // Constructor that takes shape and dtype
    Tensor(const std::vector<float>& shape, Dtype dtype = Dtype::FLOAT32)
        : shape_(shape), dtype_(dtype) {
        // Compute total number of elements
        size_ = 1;
        for (int d : shape_) {
            // If shape has zeros or negatives, consider error handling here.
            size_ *= d;
        }

        // Determine the size in bytes per element based on dtype
        element_size_ = dtypeElementSize(dtype_);

        // Allocate memory
        data_ = malloc(size_ * element_size_);
        if (!data_) {
            throw std::runtime_error("Failed to allocate memory for Tensor data");
        }

        // Initialize memory to zeros. For floating types, this sets all bits to 0.0.
        // For integer types, 0 is also correct as default.
        std::memset(data_, 0, size_ * element_size_);
    }

    // Destructor to free memory
    ~Tensor() {
        if (data_) {
            free(data_);
            data_ = nullptr;
        }
    }

    // Copy constructor for safe copying
    Tensor(const Tensor& other)
        : shape_(other.shape_), dtype_(other.dtype_), size_(other.size_), element_size_(other.element_size_) {
        data_ = malloc(size_ * element_size_);
        if (!data_) {
            throw std::runtime_error("Failed to allocate memory in copy constructor");
        }
        std::memcpy(data_, other.data_, size_ * element_size_);
    }

    // Print info about the tensor
    void printInfo() const {
        std::cout << "Shape: (";
        for (size_t i = 0; i < shape_.size(); i++) {
            std::cout << shape_[i] << (i+1 < shape_.size()? ", ":"");
        }
        std::cout << "), size=" << size_ << ", dtype=" << dtypeToString(dtype_) << "\n";
    }

    // Return a pointer to the data (non-const)
    void* data() {
        return data_;
    }

    // Return a pointer to the data (const version)
    const void* data() const {
        return data_;
    }

    const std::vector<int>& shape() const {
        return shape_;
    }

    int size() const {
        return size_;
    }

    Dtype dtype() const {
        return dtype_;
    }

private:
    std::vector<int> shape_;
    int size_;
    Dtype dtype_;
    size_t element_size_;
    void* data_ = nullptr; // raw memory for the tensor data

    size_t dtypeElementSize(Dtype dt) const {
        switch (dt) {
            case Dtype::FLOAT16: return 2;
            case Dtype::BFLOAT16: return 2;
            case Dtype::FLOAT32: return 4;
            case Dtype::FLOAT64: return 8;
            case Dtype::INT32: return 4;
            default:
                throw std::runtime_error("Unknown dtype");
        }
    }

    const char* dtypeToString(Dtype dt) const {
        switch (dt) {
            case Dtype::FLOAT16: return "float16";
            case Dtype::BFLOAT16: return "bfloat16";
            case Dtype::FLOAT32: return "float32";
            case Dtype::FLOAT64: return "float64";
            case Dtype::INT32: return "int32";
            default: return "unknown";
        }
    }
};

// Example usage (would normally go in a main.cpp or a test):
int main() {
    Tensor t({2, 3}, Dtype::FLOAT32);
    t.printInfo(); // should print shape, size, dtype

    // Access data as float*
    float* fdata = (float*)t.data();
    for (int i = 0; i < t.size(); i++) {
        fdata[i] = (float)i; 
    }

    // Print the data
    for (int i = 0; i < t.size(); i++) {
        std::cout << fdata[i] << " ";
    }
    std::cout << "\n";

    return 0;
}
