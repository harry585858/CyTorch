#include <vector>
using namespace std;
class vertex{
public:
    virtual void print();
};
class vertex_4 : vertex{
    vector<float> weight;//weight
    float bias;
public:
    void print() override;
};
class vertex_8 : vertex{
    vector<double> weight;//weight
    double bias;
public:
    void print() override;
};
