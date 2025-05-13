#ifndef LAYER_H
#define LAYER_H

#include <vector>
#include "vertex.h"

class Layer {
public:
    Layer* front;
    Layer* rear;
    std::vector<vertex> arr;
    virtual void print();
    // 전방과 후방 링크를 처리할 수 있는 append() 메소드 (예시로 구현)
    void append(Layer* toappend);

    virtual ~Layer() = default;  // 기본 소멸자, 필요 시 오버라이드 가능
    virtual void printrear();
    Layer(int size);  // 기본 생성자
};
#endif // LAYER_H
