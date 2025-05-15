#include "model.h"
#include <cstdio>
#include <fstream>
#include <sstream>
Model::Model(int num, vector<int> arr){
    int inputsize = arr[0];
    int outputsize = arr[num+1];
    larr.resize(num);
    inp = new Layer_input(inputsize);
    larr[0] = new Layer_4(1);
    for(int i=1;i<num;i++){
        larr[i] = new Layer_4(1);
        larr[i-1]->append(larr[i]);
    }
    outp = new Layer_output(outputsize);
    larr[num-1]->append(outp);
}
Model::~Model(){
    delete inp;
    delete outp;
    for(int i=0; i < larr.size();i++){
        delete larr[i];
    }
}
void Model::save() {
    std::ofstream out("model.json");
    out << "{" << std::endl;

    for (int i = 0; i < larr.size(); i++) {
        for (int j = 0; j < larr[i]->varr.size(); j++) {
            std::string key = "layer" + std::to_string(i) + "." + std::to_string(j) + ".weight";
            out << "  \"" << key << "\": [";

            // 가중치 벡터 출력
            for (int k = 0; k < larr[i]->varr[j].weight.size(); k++) {
                out << larr[i]->varr[j].weight[k];
                if (k != larr[i]->varr[j].weight.size() - 1)
                    out << ", ";
            }

            out << "]";
            
            // 마지막 항목이 아니면 쉼표 붙임
            if (!(i == larr.size() - 1 && j == larr[i]->varr.size() - 1))
                out << ",";

            out << std::endl;
        }
    }

    out << "}" << std::endl;
    out.close();
}
