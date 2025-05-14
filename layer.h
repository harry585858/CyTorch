#include <vector>
#include "vertex.h"

// 공통 기본 클래스
class Layer {
public:
    Layer* front;
    Layer* rear;

    virtual ~Layer() = default;  // 소멸자에 virtual 추가

    // 다형성을 위한 virtual 함수들
    virtual void print() = 0;
    virtual void printrear() = 0;
};

// 템플릿 클래스 (구체적인 Layer 타입)
class Layer_4 : public Layer {
public:
    std::vector<vertex_4> varr;

    Layer_4(int size);

    void print() override;

    void printrear() override;

    void append(Layer_4* toappend);
};

class Layer_8 : public Layer {
public:
    std::vector<vertex_8> varr;

    Layer_8(int size);

    void print() override;

    void printrear() override;

    void append(Layer_8* toappend);
};
