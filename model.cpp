#include "model.h"
#include <cstdio>
#include <fstream>
#include <sstream>
#include "loss.h"
#define save_direction "/Users/yangjaemin/Desktop/model.json"
Model::Model(int num, vector<int> arr){
    int outputsize = arr[num-1];
    larr.resize(num-1);
    larr[0] = new Layer_4(arr[0]); //input layer
    for(int i=1;i<num-1;i++){
        larr[i] = new Layer_4(arr[i]);
        larr[i-1]->append(larr[i]);
    }
    outp = new Layer_output(outputsize);
    larr[num-2]->append(outp);
    for(int i=1; i < larr.size();i++){
        larr[i]->init();
    }
    for(int i = 0; i < larr[0]->varr.size(); i++){
        larr[0]->varr[i].weight.resize(1);
        larr[0]->varr[i].input.resize(1);
        larr[0]->varr[i].bias = 0.0;
        larr[0]->varr[i].weight[0] = 1.0;
    }
}
Model::~Model(){
    delete outp;
    for(int i=0; i < larr.size();i++){
        delete larr[i];
    }
}
void Model::save() {
    std::ofstream out(save_direction);
    if (!out.is_open()) {
        printf("cannot open \n");
        return;
    }
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
void Model::print(){
    for(int i=0; i < larr.size(); i++){
        larr[i]->print();
    }
}
vector<float> Model::foward(vector<float> firstlayer){
    if(firstlayer.size() != larr[0]->varr.size()){
        printf("Input Layer Size Error");
        return {};
    }
    printf("---FOWARD_START!---\n");
    for(int i=0;i<firstlayer.size();i++){//input layer setting
        larr[0]->varr[i].input[0] = firstlayer[i];
    }
    for(int i=0;i<larr.size(); i++){
        larr[i]->foward();
    }
    return outp->foward();
}
void Model::init(){
    for(int i=1; i<larr.size(); i++){
        larr[i]->init();
    }
}
void Model::fit(vector<float> input, vector<float> expected_output) {
    // 1. 순전파 수행 및 예측값 받기
    vector<float> prediction = foward(input);

    // 2. 손실 및 출력층 delta 계산
    float losssum = 0.0f;
    for (int i = 0; i < prediction.size(); i++) {
        float diff = prediction[i] - expected_output[i];
        losssum += loss(prediction[i],expected_output[i]);
    }
    // 3. 손실 출력 (디버깅용)
    printf("Average Loss: %f\n", losssum/outp->varr.size());
}
