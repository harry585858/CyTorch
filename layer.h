#include <vector>
#include "vertex.h"

// 공통 기본 클래스
class Layer {
public:
    std::vector<vertex> varr;
    Layer* front;
    Layer* rear;
    virtual ~Layer() = default;  // 소멸자에 virtual 추가
    // 다형성을 위한 virtual 함수들
    virtual void print() = 0;
    virtual void printrear() = 0;
    virtual void init()=0;
    void append(Layer* toappend);
    void foward();
};

// 템플릿 클래스 (구체적인 Layer 타입)
class Layer_4 : public Layer {
public:
    float (Layer::*fp)(float);
    std::vector<vertex_4> varr;

    Layer_4(int size);

    void print() override;

    void printrear() override;

    void append(Layer_4* toappend);
    void append(Layer* toappend);
    void init() override;
};

class Layer_output : public Layer{
public:
    double (Layer::*fp)(double);
    std::vector<vertex_4> varr;

    Layer_output(int size);
    
    void foward();
    
    void print() override;

    void printrear() override;

    void append(Layer_4* toappend);
    void init() override;
};
