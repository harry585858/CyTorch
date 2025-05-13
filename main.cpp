//
//  main.cpp
//  cytorch
//
//  Created by 양재민 on 5/13/25.
//
//
#include <iostream>
#include <vector>
#include <stdio.h>
#include "layer.h"
using namespace std;
int main() {
    Layer newone(5);
    Layer backone(6);
    newone.append(&backone);
    newone.print();
    return 0;
}
