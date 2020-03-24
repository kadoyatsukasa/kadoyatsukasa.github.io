//
// Created by ErikLu on 2020/3/13.
//

#include <iostream>
#include<vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main()
{
    vector<int> ivec;
    int elem;
    int sum;

    cout<<"Enter integers,q to quit"<<endl;

    while (cin>>elem && elem!='q')
        ivec.push_back(elem);

    vector<int>::iterator iter;
    for(iter=ivec.begin();iter!=ivec.end();++iter)
        sum+=*iter;
    cout<<"sum is "<<sum<<endl;
    return 0;
}