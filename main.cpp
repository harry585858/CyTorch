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
    Layer_4 newone(4);
    Layer_4 otherone(5);
    newone.append(&otherone);
    newone.printrear();
    return 0;
}
