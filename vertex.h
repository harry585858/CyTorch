#include <vector>
#include "activation.h"
using namespace std;
class vertex{
public:
    virtual void print() = 0; // 순수 가상 함수
    virtual ~vertex() = default; // 가상 소멸자 추가
    vector<float> input, weight;
    virtual float foward()= 0;
    virtual void init()=0;
};

class vertex_4 : public vertex {
public:
    float bias, tmp;
    float (*fp)(float)=relu;
    vector<float> input, weight;
    void print() override; // 부모 클래스의 virtual 함수 오버라이드
    float foward() override;
    vertex_4();
    void init();
};
