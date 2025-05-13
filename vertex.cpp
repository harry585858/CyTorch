#include "vertex.h"
#include <stdio.h>
#include <vector>
void vertex_4::print(){
    printf("bias : %lf", this->bias);
    printf("weight : ");
    for(int i=0;i<this->weight.size(); i++){
        printf("%lf", this->weight[i]);
    }
}
void vertex_8::print(){
    printf("bias : %lf", this->bias);
    printf("weight : ");
    for(int i=0;i<this->weight.size(); i++){
        printf("%lf", this->weight[i]);
    }
}
