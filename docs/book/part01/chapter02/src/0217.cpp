//
// Created by ErikLu on 2020/3/14.
//

#include <iostream>
int main(){

    int i , &ri = i;
    i = 5;
    ri = 10;
    std::cout<<i<<"  "<<ri<<std::endl;

    return 0;
}