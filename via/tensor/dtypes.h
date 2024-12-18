#ifndef VIA_TENSOR_DTYPES_H
#define VIA_TENSOR_DTYPES_H

#include <cstddef>
#include <stdexcept>

namespace via {
    enum class Dtype {
        FLOAT16,
        FLOAT32,
        FLOAT64,
        INT32,
        BFLOAT16
        // Add more as needed
    };

    inline size_t dtypeElementSize(Dtype dt) {
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

    inline const char* dtypeToString(Dtype dt) {
        switch (dt) {
            case Dtype::FLOAT16: return "float16";
            case Dtype::BFLOAT16: return "bfloat16";
            case Dtype::FLOAT32: return "float32";
            case Dtype::FLOAT64: return "float64";
            case Dtype::INT32: return "int32";
            default: return "unknown";
        }
    }
}

#endif // VIA_TENSOR_DTYPES_H
