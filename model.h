#include <vector>
#include "layer.h"

class Model{
public:
    Layer_output* outp;
    vector<Layer_4*> larr;
    Model(int num, vector<int> arr);
    ~Model();
    void save();
    void print();
    vector<float> forward(vector<float>);
    void init();
    void fit(vector<float> input, vector<float> output);
};
