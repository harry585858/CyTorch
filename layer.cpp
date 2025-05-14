#include "layer.h"
#include <cstdio>
// 템플릿 구현
void Layer::runlayer(){
    for(int i=0;i<this->varr.size(); i++){
        auto output = varr[i].runvertex();
        for(int j = 0; j < this->rear->varr.size(); j++){//next input
            this->rear->varr[j].weight[i] = output;
        }
    }
}
Layer_4::Layer_4(int size) {
    front = nullptr;
    rear = nullptr;
    varr.resize(size);
}
void Layer_4::append(Layer_4* toappend) {
    toappend->front = this;
    toappend->rear = this->rear;
    this->rear = toappend;
    for(int i=0;i<toappend->varr.size(); i++){
        toappend->varr[i].weight.resize(this->varr.size());
    }
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
void Layer_8::append(Layer_8* toappend) {
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
Endlayer::Endlayer(int size){
    front = nullptr;
    rear = nullptr;
    varr.resize(size);
}
void Endlayer::printrear() {
    Layer* start = this;
    while (start != nullptr) {
        start->print();
        start = static_cast<Layer*>(start->rear);
    }
}

void Endlayer::print() {
    for (int i = 0; i < varr.size(); i++) {
        std::cout << "vertex : " << i << std::endl;
        varr[i].print();
    }
    
    std::cout << std::endl;
}
void Endlayer::runlayer(){
    this->print();
    printf("---THE END!---\n");
    for(int i=0;i<this->varr.size(); i++){
        auto output = varr[i].runvertex();
        printf("%lf ", output);
    }
}
