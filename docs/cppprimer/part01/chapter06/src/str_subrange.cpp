//  [3/12/2020 Erik]
/**
 * 错误返回值
 */
#include<iostream>
#include<string>

using std::cout;
using std::endl;
using std::string;

//  [3/12/2020 Erik]
//因为含有不正确的返回值,所以这段代码无法通过编译
bool str_subrange(const string& str1, const string& str2) {
    if (str1.size() == str2.size())
        return str1 == str2;
    auto size = (str1.size() < str2.size()) ? str1.size() : str2.size();

    for (decltype(size) i =0;i!=size;++i)
        if (str1[i] != str2[i])
            return; //错误#1 ：没有返回值,编译器将报告这一错误

    //错误#2：控制流可能尚未返回任何值就结束了函数的执行
    //编译器可能检查不出这一错误
}

int main() {
    string str1 = "hello";
    string str2 = "world";

    str_subrange(str1, str2);
   

    return 0;
}
