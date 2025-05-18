#include "layer.h"
#include <cstdio>
// 템플릿 구현
void Layer::foward(){
    for(int i=0;i<this->varr.size(); i++){
        auto output = varr[i].foward();
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
        toappend->varr[i].input.resize(this->varr.size());
    }
}
void Layer_4::append(Layer* toappend) {
    toappend->front = this;
    toappend->rear = this->rear;
    this->rear = toappend;
    for(int i=0;i<toappend->varr.size(); i++){
        toappend->varr[i].weight.resize(this->varr.size());
        toappend->varr[i].input.resize(this->varr.size());
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
void Layer_output::foward(){
    this->print();
    printf("---THE END!---\n");
    for(int i=0;i<this->varr.size(); i++){
        auto output = varr[i].foward();
        printf("%lf ", output);
    }
}
