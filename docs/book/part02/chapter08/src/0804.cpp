#include<iostream>
#include<fstream>
#include<vector>
#include<ios>
#include<string>

using std::vector;
using std::ifstream;
using std::ofstream;
using std::fstream;
using std::string;
using std::ios_base;
using std::cout;
using std::cin;
using std::endl;

// 从指定文件读取字符串并存放到vector中
// @param filePath 指定文件的路径
// @return 返回存储的容器
vector<string> readFileToVector(string filePath){
    vector<string> fileString;
    string text;
    ifstream input(filePath); //建立文件关联
    input.open(filePath,ios_base::in); //以读的形式打开指定文件


//如果没有达到文件结尾
//就持续读文件
    if(input){
        while (!input.eof())
        {
            std::getline(input,text);
            fileString.push_back(text); //将内容保存到vector之中
        }
    }
    
    fileString.pop_back();
    input.close();
    return fileString;
}

int main(int argc, char const *argv[])
{
    vector<string> resultString;
    string filePath;
    
    cout<<"Enter the path of file: "<<endl;
    cin>>filePath;
    resultString=readFileToVector(filePath);

    cout<<"Context of the file :"<<endl;

    for(string s:resultString)
        cout<<s;

    return 0;
}
