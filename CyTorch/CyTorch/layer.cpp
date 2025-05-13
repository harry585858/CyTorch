#include "layer.h"
#include <iostream>
// 템플릿 구현
Layer_4::Layer_4(int size) {
    front = nullptr;
    rear = nullptr;
    varr.resize(size);
}
void Layer_4::append(Layer* toappend) {
    toappend->front = this;
    toappend->rear = this->rear;
    this->rear = toappend;
}

void Layer_4::printrear() {
    Layer* start = this;
    while (start != nullptr) {
        start->print();
        start = static_cast<Layer*>(start->rear);
    }
}

void Layer_4::print() {
    for (int i = 0; i < varr.size(); i++) {
        std::cout << "vertex : " << i << std::endl;
        varr[i].print();
    }
    std::cout << std::endl;
}

// 명시적 인스턴스화: Layer 클래스가 float, double을 처리할 수 있도록 인스턴스화
Layer_8::Layer_8(int size) {
    front = nullptr;
    rear = nullptr;
    varr.resize(size);
}
void Layer_8::append(Layer* toappend) {
    toappend->front = this;
    toappend->rear = this->rear;
    this->rear = toappend;
}

void Layer_8::printrear() {
    Layer* start = this;
    while (start != nullptr) {
        start->print();
        start = static_cast<Layer*>(start->rear);
    }
}

void Layer_8::print() {
    for (int i = 0; i < varr.size(); i++) {
        std::cout << "vertex : " << i << std::endl;
        varr[i].print();
    }
    std::cout << std::endl;
}
