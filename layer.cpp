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
void Layer_4::append(Layer* toappend) {
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
Layer_input::Layer_input(int size){
    front = nullptr;
    rear = nullptr;
    varr.resize(size);
}
void Layer_input::printrear() {
    Layer* start = this;
    while (start != nullptr) {
        start->print();
        start = static_cast<Layer*>(start->rear);
    }
}

void Layer_input::print() {
    for (int i = 0; i < varr.size(); i++) {
        std::cout << "vertex : " << i << std::endl;
        varr[i].print();
    }
    
    std::cout << std::endl;
}
void Layer_input::runlayer(){
    this->print();
    printf("---THE END!---\n");
    for(int i=0;i<this->varr.size(); i++){
        auto output = varr[i].runvertex();
        printf("%lf ", output);
    }
}

Layer_output::Layer_output(int size){
    front = nullptr;
    rear = nullptr;
    varr.resize(size);
}
void Layer_output::printrear() {
    Layer* start = this;
    while (start != nullptr) {
        start->print();
        start = static_cast<Layer*>(start->rear);
    }
}

void Layer_output::print() {
    for (int i = 0; i < varr.size(); i++) {
        std::cout << "vertex : " << i << std::endl;
        varr[i].print();
    }
    
    std::cout << std::endl;
}
void Layer_output::runlayer(){
    this->print();
    printf("---THE END!---\n");
    for(int i=0;i<this->varr.size(); i++){
        auto output = varr[i].runvertex();
        printf("%lf ", output);
    }
}
