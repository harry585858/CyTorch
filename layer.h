#ifndef LAYER_H
#define LAYER_H

#include <vector>
#include "vertex.h"

// 공통 기본 클래스
class BaseLayer {
public:
    BaseLayer* front;
    BaseLayer* rear;

    virtual ~BaseLayer() = default;
    virtual void print() = 0;  // 다형성을 위한 virtual 함수
    virtual void printrear() = 0;
};

// 템플릿 클래스 (구체적인 Layer 타입)
template <typename T>
class Layer : public BaseLayer {
public:
    std::vector<vertex<T>> arr;

    Layer(int size);
    virtual ~Layer() = default;

    virtual void print() override;
    virtual void printrear() override;
    void append(BaseLayer* toappend);
};

#endif // LAYER_H
