#ifndef VIA_EXCEPTIONS_H
#define VIA_EXCEPTIONS_H

#include <stdexcept>
#include <string>

namespace via {

class TensorShapeError : public std::runtime_error {
public:
    explicit TensorShapeError(const std::string& msg) : std::runtime_error(msg) {}
};

class DtypeError : public std::runtime_error {
public:
    explicit DtypeError(const std::string& msg) : std::runtime_error(msg) {}
};

class DeviceError : public std::runtime_error {
public:
    explicit DeviceError(const std::string& msg) : std::runtime_error(msg) {}
};

// Add more as needed...

}

#endif // VIA_EXCEPTIONS_H
