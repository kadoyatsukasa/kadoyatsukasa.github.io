//
// Created by ErikLu on 2020/3/13.
//

#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
    int start;
    int end;

    cout<<"Enter two numbers "<<endl;
    cin>>start>>end;
    cout<<endl;

    if(start<=end){
        while (start<=end)
            cout<<start++<<'\t';
    } else if(start>=end){
        while (start>=end)
            cout<<start--<<'\t';
    }

    cout<<endl;
    return 0;
}