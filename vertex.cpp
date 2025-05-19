// vertex.cpp
#include "vertex.h"
#include <cstdio>
#include <cstdlib>
#include <ctime>
void vertex_4::init(){
    // [-1, 1]  float
    for(int i=0; i<weight.size(); i++){
    float w = ((float)rand() / RAND_MAX) * 2.0f - 1.0f;
    weight[i] = w;
    }
    bias = ((float)rand() / RAND_MAX) * 2.0f - 1.0f;
}
vertex_4::vertex_4(){
    // bias
    bias = ((float)rand() / RAND_MAX) * 2.0f - 1.0f;
}
void vertex_4::print() {
    printf("bias : %f\nweight : ", this->bias);  // float의 경우 %f 사용
    for (int i = 0; i < this->weight.size(); i++) {
        printf("%f ", this->weight[i]);  // float의 경우 %f 사용
    }
    printf("\n");
}
float vertex_4::forward(){
    float sum = 0.0f;
    for(int i=0;i<this->input.size(); i++){
        sum += weight[i] * input[i];
    }
    sum+=bias;
    output = fp(sum);
    return fp(sum);
}
