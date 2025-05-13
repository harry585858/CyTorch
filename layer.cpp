#include "layer.h"
#include <iostream>

// 템플릿 구현

template <typename T>
Layer<T>::Layer(int size) {
    front = nullptr;
    rear = nullptr;
    arr.resize(size);
}

template <typename T>
void Layer<T>::append(BaseLayer* toappend) {
    toappend->front = this;
    toappend->rear = this->rear;
    this->rear = toappend;
}

template <typename T>
void Layer<T>::printrear() {
    Layer<T>* start = this;
    while (start != nullptr) {
        start->print();
        start = static_cast<Layer<T>*>(start->rear);
    }
}

template <typename T>
void Layer<T>::print() {
    for (int i = 0; i < arr.size(); i++) {
        std::cout << "vertex : " << i << std::endl;
        arr[i].print();
    }
    std::cout << std::endl;
}

// 명시적 인스턴스화: Layer 클래스가 float, double을 처리할 수 있도록 인스턴스화
template class Layer<float>;
template class Layer<double>;
