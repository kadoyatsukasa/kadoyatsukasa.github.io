//
// Created by ErikLu on 2020/3/14.
//

#include <iostream>
using std::cout;
using std::endl;

int main(){
    const int i = 42;
    auto j = i ;
    const auto &k = i;
    auto *p = &i;
    const auto j2 = i;
    const auto &k2 = i;

    cout<< "j = "<<j<<endl;
    cout<<" &k = "<<&k<<" , k = " <<k<<endl;
    cout<<"*p = "<<*p<<" , p = "<<p<<endl;
    cout<<"j2 = "<<j2<<endl;
    cout<<"&k2 = "<<&k2<<" , k2 = "<<k2<<endl;

    return 0;
}