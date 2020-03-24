#include "personInfo.h"
#include<iostream>

using std::cin;

//将读取的内容保存到容器中
//
// 将一系列第一个参数保存到第二个参数的容器中
// @param info 读取的一条内容的引用
// @param pvect 目标容器
void savePersonInfoAsVector(PersonInfo& info,vector<PersonInfo> pvect){
    string line,word;
    string tName;
    vector<string> tPhones;

    while(std::getline(cin,line)){
        PersonInfo temp;
        istringstream record(line);
        record>>tName;
        info.setName(tName);
        while (record>>word)
        {
            tPhones.push_back(word);
            info.setPhones(tPhones);
        }
        pvect.push_back(temp);
    }
}