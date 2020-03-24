//
// Created by ErikLu on 2020/3/14.
//

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
    int currVal=0;
    int val=0;

    if(cin>>currVal){
        int cnt=1;
        while (cin>>currVal){
            if(val==currVal) ++cnt;
            else{
                cout<<currVal<<" occurs "<<cnt<<" times "<<endl;
                currVal=val;
                cnt=1;
            }
        }
        cout<<currVal<<" occurs "<<cnt<<" times "<<endl;
    }
    return 0;
}