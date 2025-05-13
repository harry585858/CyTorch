#include "layer.h"
#include <iostream>

Layer::Layer() : front(nullptr), rear(nullptr) {}
Layer::~Layer() {}
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
Layer_4::Layer_4(int size, std::vector<float> init) {
    arr = init;
}

void Layer_4::print() {
    for (int i = 0; i < arr.size(); i++) {
        std::printf("%f ", arr[i]);
    }
    std::printf("\n");
}

Layer_8::Layer_8(int size) {
    arr.resize(size);
}

Layer_8::Layer_8(int size, std::vector<double> init) {
    arr = init;
}

void Layer_8::print() {
    for (int i = 0; i < arr.size(); i++) {
        std::printf("%lf ", arr[i]);
    }
    std::printf("\n");
}
