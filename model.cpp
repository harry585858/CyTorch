#include "model.h"
#include <fstream>
void Model::save(){
    std::ofstream out("output.txt", std::ios::app);
    for(int i=0; i < larr.size();i++){
        for(int j=0; j <larr[i]->varr.size();j++){
            for(int k=0; k < larr[i]->varr[0].weight.size(); k++){
                out << larr[i]->varr[j].weight[k];
            }
        }
        cout << "--";//perlayer
    }
    out.close();
}
