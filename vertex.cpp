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

void vertex_8::print() {
    printf("bias : %lf\nweight : ", this->bias);  // double의 경우 %lf 사용
    for (int i = 0; i < this->weight.size(); i++) {
        printf("%lf ", this->weight[i]);  // double의 경우 %lf 사용
    }
    printf("\n");
}
