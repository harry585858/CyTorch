#include "layer.h"
#include <cstdio>
void Layer::foward(){
    for(int i=0;i<this->varr.size(); i++){
        auto output = varr[i].foward();
        for(int j = 0; j < this->rear->varr.size(); j++){//next input
            rear->varr[j].input[i] = output;
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
        printf("vertex : %d\n", i);
        varr[i].print();
    }
    printf("\n");
}
void Layer_4::init(){
    for(int i=0; i<varr.size();i++){
        varr[i].init();
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
        printf("vertex : %d\n", i);
        varr[i].print();
    }
    printf("\n");
}
vector<float> Layer_output::foward(){
    vector<float> toreturn(varr.size());
    for(int i=0;i<this->varr.size(); i++){
        double output = varr[i].foward();
        printf("%lf ", output);
        toreturn[i] = output;
    }
    printf("---THE END!---\n");
    return toreturn;
}
void Layer_output::init(){
}
