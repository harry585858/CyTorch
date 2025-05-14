#include <vector>
#include <iostream>
using namespace std;

class vertex {
public:
    vertex() = default; 
    template <typename T>
    T relu(T t) {
        return (t < 0) ? 0 : t;
    }
    virtual void print() = 0; // 순수 가상 함수
    virtual ~vertex() = default; // 가상 소멸자 추가
};

class vertex_4 : public vertex {
public:
    float bias, output;
    vector<float> weight;
    void print() override; // 부모 클래스의 virtual 함수 오버라이드
};

class vertex_8 : public vertex {
public:
    double bias, output;
    vector<double> weight;
    void print() override; // 부모 클래스의 virtual 함수 오버라이드
};
