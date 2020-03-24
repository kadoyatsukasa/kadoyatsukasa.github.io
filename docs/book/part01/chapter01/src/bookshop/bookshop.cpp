//
// Created by ErikLu on 2020/3/14.
//

#include "Sales_item.h"
#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::vector;
using std::endl;
using std::cerr;

int main(){
    Sales_item total;   //保存下一条交易记录的变量
    if(cin>>total){
        Sales_item trans;   //保存和的变量

        while (cin>>trans){
            if(total.isbn()==trans.isbn()) total+=trans;
            else{
                cout<<total<<endl;
                total=trans;
            }
        }
        cout<<total<<endl;
    } else{
        cerr<<"No input"<<endl;
        return -1;
    }

    return 0;
}