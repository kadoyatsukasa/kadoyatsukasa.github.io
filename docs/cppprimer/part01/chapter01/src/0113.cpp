//
// Created by ErikLu on 2020/3/13.
//

#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int fun_0109(){
    int sum=0;
    for(int i=50;i<=100;i++){
        sum+=i;
    }
    return sum;
}

void fun_0110(int start=0,int end=10){
    for(int i=start;i<=end;i++)
        cout<<i<<'\t';
    cout<<endl;
}

void fun_0111(int start,int end){
    if(start>=end){
        for(int s=start;s>=end;s--){
            cout<<s<<'\t';
        }
    } else if(start<=end){
        for(int s=start;s<=end;s++){
            cout<<s<<'\t';
        }
    }
}

int main(){
    int start;
    int end;

    cout<<"Sum of all  integers between 50 and 100 is "<<fun_0109()<<endl;
    cout<<"Integers from 10 to 0 are "<<endl;
    fun_0110();
    cout<<"Enter two numbers"<<endl;
    cin>>start>>end;
    fun_0111(start,end);
    cout<<endl;
    return 0;
}