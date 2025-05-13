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
Layer_4::Layer_4(int size) {
    arr.resize(size);
}

void Layer_4::print() {
    for (int i = 0; i < arr.size(); i++) {
        arr[i].print();
    }
    std::printf("\n");
}

Layer_8::Layer_8(int size) {
    arr.resize(size);
}

void Layer_8::print() {
    for (int i = 0; i < arr.size(); i++) {
        arr[i].print();
    }
    std::printf("\n");
}
