#include "activation.h"
float relu(float t){
    return (t < 0) ? 0 : t;
}
double relu(double t){
    return (t < 0) ? 0 : t;
}
