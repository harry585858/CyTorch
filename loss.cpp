#include "loss.h"
float loss(float a, float b){
    return 0.5f* (a-b)*(a-b);
}
double loss(double a, double b){
    return 0.5f * (a-b)*(a-b);
}
float loss_d(float pred, float target) {
    return pred - target;  // d(0.5 * (pred - target)^2) / dpred
}
double loss_d(double pred, double target) {
    return pred - target;  // d(0.5 * (pred - target)^2) / dpred
}
