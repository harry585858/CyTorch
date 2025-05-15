#include <vector>
#include "layer.h"

class Model{
public:
    Layer_input* inp;
    Layer_output* outp;
    vector<Layer_4*> larr;
    Model(int num, vector<int> arr);
    ~Model();
    void save();
    void run();
    void print();
};
