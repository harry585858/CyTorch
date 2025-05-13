#include "layer.h"
#include <iostream>
//https://github.com/harry585858/CyTorch.git
void Layer::append(Layer* toappend){//add layer
    toappend->front = this;
    toappend->rear = this->rear;
    this->rear = toappend;
}
void Layer::printrear(){
    Layer* start = this;
    while(start != nullptr){
        (*start).print();
        start = start->rear;
    }
}
Layer::Layer(int size) {
    arr.resize(size);
}

void Layer::print() {
    for (int i = 0; i < arr.size(); i++) {
        printf("vertex : %d\n", i);
        arr[i].print();
    }
    std::printf("\n");
}
