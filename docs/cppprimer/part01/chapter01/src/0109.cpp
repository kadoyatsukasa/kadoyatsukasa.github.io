//
// Created by ErikLu on 2020/3/13.
//

#include<iostream>

using std::cout;
using std::endl;

int main()
{
    int sum=0;
    int start=50;

    while(start<=100){
        sum+=start;
        ++start;
    }

    cout<<"Sum of integers from 50 to 100 is "<<sum<<endl;

    return 0;
}