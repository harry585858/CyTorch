#ifndef LAYER_H
#define LAYER_H

#include <vector>
#include "vertex.h"

// Layer는 추상 클래스입니다. (순수 가상 함수 포함)
class Layer {
public:
    Layer* front;
    Layer* rear;

    // 순수 가상 함수: 모든 하위 클래스는 print() 메소드를 반드시 구현해야 합니다.
    virtual void print();

    // 전방과 후방 링크를 처리할 수 있는 append() 메소드 (예시로 구현)
    void append(Layer* toappend);

    virtual ~Layer() = default;  // 기본 소멸자, 필요 시 오버라이드 가능
    virtual void printrear();
protected:
    Layer() : front(nullptr), rear(nullptr) {}  // 기본 생성자
};

// Layer_4 클래스는 Layer 클래스를 상속받아 구현합니다.
class Layer_4 : public Layer {
private:
    std::vector<vertex_4> arr;  // vertex_4 객체를 저장하는 벡터

public:
    // 생성자
    Layer_4(int size);
    Layer_4(int size, const std::vector<float>& init);

    // print 함수 오버라이드
    void print() override;
};

// Layer_8 클래스는 Layer 클래스를 상속받아 구현합니다.
class Layer_8 : public Layer {
private:
    std::vector<vertex_8> arr;  // vertex_8 객체를 저장하는 벡터

public:
    // 생성자
    Layer_8(int size);
    Layer_8(int size, const std::vector<double>& init);

    // print 함수 오버라이드
    void print() override;
};

#endif // LAYER_H
