#include "layer.h"
#include <cstdio>
void Layer::forward(){
    for(int i=0;i<this->varr.size(); i++){
        auto output = varr[i].forward();
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
void Layer_4::update_weights(float learning_rate) {
    for (int i = 0; i < varr.size(); i++) {
        for (int j = 0; j < varr[i].weight.size(); j++) {
            varr[i].weight[j] -= learning_rate * varr[i].delta * varr[i].input[j];
        }
        varr[i].bias -= learning_rate * varr[i].delta;
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
vector<float> Layer_output::forward(){
    vector<float> toreturn(varr.size());
    for(int i=0;i<this->varr.size(); i++){
        double output = varr[i].forward();
        printf("%lf ", output);
        toreturn[i] = output;
    }
    printf("---THE END!---\n");
    return toreturn;
}
void Layer_output::update_weights(float learning_rate) {
    for (int i = 0; i < varr.size(); i++) {
        for (int j = 0; j < varr[i].weight.size(); j++) {
            varr[i].weight[j] -= learning_rate * varr[i].delta * varr[i].input[j];
        }
        varr[i].bias -= learning_rate * varr[i].delta;
    }
}
void Layer_output::init(){
}
