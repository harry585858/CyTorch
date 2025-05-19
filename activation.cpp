#include "activation.h"
float relu(float t){
    return (t < 0) ? 0.0f : t;
}
double relu(double t){
    return (t < 0) ? 0.0 : t;
}
float relu_d(float t){
    return t < 0.0f ? 0.0f : 1.0f;
}
double relu_d(double t){
    return t < 0.0 ? 0.0 : 1.0;
}
