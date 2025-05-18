// vertex.cpp
#include "vertex.h"
#include <cstdio>
void vertex_4::print() {
    printf("bias : %f\nweight : ", this->bias);  // float의 경우 %f 사용
    for (int i = 0; i < this->weight.size(); i++) {
        printf("%f ", this->weight[i]);  // float의 경우 %f 사용
    }
    std::cout << "\n";
}
float vertex_4::foward(){
    float sum = 0;
    for(int i=0;i<this->input.size(); i++){
        sum += weight[i] * input[i];
    }
    sum+=bias;
    return fp(sum);
}
