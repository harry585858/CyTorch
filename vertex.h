#pragma once
#include <vector>
#include <iostream>

template <typename T>
class vertex {
    std::vector<T> weight;
    T bias, output;
public:
    vertex() = default;

    T ReLU(T t) {
        return (t < 0) ? 0 : t;
    }

    void print() const {
        std::cout << "bias : " << bias << "\n";
        std::cout << "weight : ";
        for (const auto& w : weight) {
            std::cout << w << " ";
        }
        std::cout << "\n";
    }

    // 예시로 bias, weight 설정 함수도 추가 가능
    void setBias(T b) { bias = b; }
    void setWeights(const std::vector<T>& w) { weight = w; }
    T getOutput() const { return output; }
};
