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
#include "model.h"
using namespace std;
int main() {
    Model model(5, {3,5,5,5,3});//layer, size
    model.foward({1.0,2.0,3.0});
    return 0;
}
