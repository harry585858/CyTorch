//
//  main.cpp
//  cytorch
//
//  Created by 양재민 on 5/13/25.
//
#include <vector>
#include <iostream>
using namespace std;
template<typename T>
#include <variant>
#include <vector>

class layer {
public:
    layer* front, *rear;

    using VariantVector = std::variant<
        std::vector<bool>,
        std::vector<float>,
        std::vector<double>
    >;
    VariantVector vec;
    layer(int size, int data) { //1 bool 4 float 8 double
        switch (data) {
            case 1:
                vec = std::vector<bool>(size);
                break;
            case 4:
                vec = std::vector<float>(size);
                break;
            case 8:
                vec = std::vector<double>(size);
                break;
            default:
                throw std::invalid_argument("Invalid data type");
        }
    }
};
int main(int argc, const char * argv[]) {
    
    return 0;
}
