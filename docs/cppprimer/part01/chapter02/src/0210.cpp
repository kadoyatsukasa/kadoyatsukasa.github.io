//
// Created by ErikLu on 2020/3/14.
//

#include <iostream>
std::string global_str;
int global_int;
int main(){
    int local_int;
    std::string local_str;

    std::cout<<"Default initializers"<<std::endl;
    std::cout<<"global_str = "<<global_str<<std::endl;
    std::cout<<"global_int = "<<global_int<<std::endl;
    std::cout<<"local_int = "<<local_int<<std::endl;
    std::cout<<"local_str = "<<local_str<<std::endl;

    return 0;
}