#include <vector>
#include "layer.h"

class Model{
    vector<Layer*> larr;
    Model(int num, int inputsize, int outputsize);
    ~Model();
    void save();
    void run();
};
