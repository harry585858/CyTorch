//
//  main.cpp
//  cytorch
//
//  Created by 양재민 on 5/13/25.
//
//
#include <iostream>
#include <vector>
#include <variant>
#include <memory>
#include <stdexcept>

using namespace std;

class layer {
public:
    layer* front = nullptr;
    layer* rear = nullptr;

    using VariantVector = variant<
        vector<bool>,
        vector<float>,
        vector<double>
    >;

    VariantVector vec;

    layer(int size, int data_type) {
        switch (data_type) {
            case 1:
                vec = vector<bool>(size, false);
                break;
            case 4:
                vec = vector<float>(size, 0.0f);
                break;
            case 8:
                vec = vector<double>(size, 0.0);
                break;
            default:
                throw invalid_argument("Unsupported data type.");
        }
    }

    void apply_activation() {
        // 예: 모든 원소에 +1 하는 간단한 연산
        visit([](auto& v) {
            for (auto& val : v) {
                val += 1;
            }
        }, vec);
    }

    void print() const {
        visit([](const auto& v) {
            for (const auto& val : v) {
                cout << val << " ";
            }
            cout << endl;
        }, vec);
    }
};

int main() {
    // 세 개의 레이어: 입력, 은닉, 출력
    layer input_layer(5, 4);   // float
    layer hidden_layer(5, 4);  // float
    layer output_layer(5, 4);  // float

    // 연결
    input_layer.rear = &hidden_layer;
    hidden_layer.front = &input_layer;
    hidden_layer.rear = &output_layer;
    output_layer.front = &hidden_layer;

    // 초기 입력값 설정
    get<vector<float>>(input_layer.vec) = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f};

    cout << "== Input Layer ==" << endl;
    input_layer.print();

    // Forward propagation (각 레이어에 +1 연산)
    hidden_layer.vec = get<vector<float>>(input_layer.vec);
    hidden_layer.apply_activation();

    output_layer.vec = get<vector<float>>(hidden_layer.vec);
    output_layer.apply_activation();

    cout << "== Output Layer ==" << endl;
    output_layer.print();

    return 0;
}
