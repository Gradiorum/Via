#include <iostream>
#include <initializer_list>
#include <vector>
#include <stdexcept>
#include <type_traits>
#include <iostream>
using namespace std;

enum class Dtype {float32, int32, float64, float16, bfloat16};

class Tensor {

public:
// Constructor that takes a shape: shape = {2,3} means 2D tensor with 2 rows and 3 columns
    Tensor (const std::vector<int>& shape) 
        : shape_(shape) //intiializes shape_ with the passed shape
    {
        size_ = 1;
        for (int d : shape_){
            size_ *= d;
        }
        //Memory is allocated for data in advance, we intialize with 0's automatically
        data_.resize(size_, 0.0f)
    }
};