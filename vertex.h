#include <vector>
#include "activation.h"
#include "loss.h"
using namespace std;
class vertex{
public:
    virtual void print() = 0; // 순수 가상 함수
    virtual ~vertex() = default; // 가상 소멸자 추가
    vector<float> input, weight;
    float delta;
    virtual float forward()= 0;
    virtual void init()=0;
};

class vertex_4 : public vertex {
public:
    float bias, tmp, delta, output;
    float (*fp)(float)=relu, (*fp_d)(float)=relu_d;
    vector<float> input, weight;
    void print() override; // 부모 클래스의 virtual 함수 오버라이드
    float forward() override;
    vertex_4();
    void init() override;
};
