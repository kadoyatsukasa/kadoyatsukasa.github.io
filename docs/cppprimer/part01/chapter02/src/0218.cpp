//
// Created by ErikLu on 2020/3/14.
//

#include <iostream>

using std::cout;
using std::endl;

int main(){
    int num=1;
    int *num_prt=&num;

    cout<<"Initialize:"<<endl;
    cout<<"num = "<<num<<endl;
    cout<<"&num = "<<&num<<endl;
    cout<<"*num_ptr = "<<*num_prt<<endl;
    cout<<"num_ptr="<<num_prt<<endl;

    int other=2;
    *num_prt=other;

    cout<<"Change"<<endl;
    cout<<"num = "<<num<<endl;
    cout<<"&num = "<<&num<<endl;
    cout<<"*num_prt = "<<*num_prt<<endl;
    cout<<"num_ptr = "<<num_prt<<endl;
    cout<<"other = "<<other<<endl;
    cout<<"&other = "<<&other<<endl;
}