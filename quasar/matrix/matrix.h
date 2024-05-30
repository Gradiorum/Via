typedef enum {
    DEVICE_CPU,
    DEVICE_GPU
    // Additional devices like DEVICE_TPU can be added here
} DeviceType;

typedef struct {
    void* data;
    int* shape;
    int rank;
    int dtype;
    int size;

} Matrix;
