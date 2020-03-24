//
// Created by ErikLu on 2020/3/14.
//

#include <iostream>
using std::cout;
using std::endl;

int main()
{
    int i = 0 ; int &r = i;
    auto a = r;
    const int ci = i,&cr=ci;
    auto b = ci;
    auto c = cr;
    auto d = &i;
    auto e = &ci;
    const auto f = ci;
    auto &g = ci;

    a=42;b=42;c=42;
    d=42;e=42;g=42;

    cout<<"a = "<<a<<" "
        <<"b = "<<b<<" "
        <<"c = "<<c<<" "
        <<"d = "<<d<<" "
        <<"e = "<<e<<" "
        <<"g = "<<g<<endl;

    return 0;
}