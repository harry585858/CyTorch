#ifndef LAYER_H
#define LAYER_H

#include <vector>

class Layer {
public:
    Layer *front, *rear;
    virtual void print() = 0;  // 순수 가상 함수 (추상 클래스)
    virtual void printrear();
    Layer();
    virtual ~Layer();
    virtual void append(Layer* left);
};

class Layer_4 : public Layer {
    std::vector<float> arr;
public:
    Layer_4(int size);
    Layer_4(int size, std::vector<float> init);
    void print() override;  // override를 사용하여 가상 함수 오버라이드
};

class Layer_8 : public Layer {
    std::vector<double> arr;
public:
    Layer_8(int size);
    Layer_8(int size, std::vector<double> init);
    void print() override;  // override를 사용하여 가상 함수 오버라이드
};

#endif // LAYER_H
