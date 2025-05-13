//
//  main.cpp
//  cytorch
//
//  Created by 양재민 on 5/13/25.
//
//
//https://github.com/harry585858/CyTorch.git
#include <iostream>
#include <vector>
#include <stdio.h>
#include "layer.h"
using namespace std;
int main() {
    Layer<float> layer1(3);  // float 타입 레이어
    Layer<double> layer2(2); // double 타입 레이어

    layer1.append(&layer2);  // 다른 타입의 레이어도 append 가능

    layer1.printrear();  // 레이어들 순차적으로 출력
}
