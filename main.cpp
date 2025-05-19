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
    srand(static_cast<unsigned int>(time(NULL)));
    Model model(3, {3,3,3});//layer, size
    model.fit({1,1,1}, {1,1,1});
    model.fit({1,1,1}, {1,1,1});
    model.fit({1,1,1}, {1,1,1});
    model.fit({1,1,1}, {1,1,1});
    return 0;
    
}
