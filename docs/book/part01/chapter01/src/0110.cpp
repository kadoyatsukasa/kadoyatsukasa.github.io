//
// Created by ErikLu on 2020/3/13.
//

#include <iostream>

using std::cout;
using std::endl;

int main()
{
    int start=10;
    cout<<"Integer between 0 to 10 (big to small)"<<endl;

    while (start>=0){
        cout<<start<<'\t';
        --start;
    }
    cout<<endl;

    return 0;
}