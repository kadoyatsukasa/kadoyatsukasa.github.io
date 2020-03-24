#include<iostream>
#include<string>

using std::istream;
using std::ostream;
using std::string;
using std::cout;
using std::cin;
using std::endl;


istream& get_stream(istream& stream){
    string output;
    while(!stream.eof())
        std::getline(stream,output);
    cout<<output;
    
    stream.clear();
    return stream;
}

int main(int argc, char const *argv[])
{
    get_stream(cin);
    // string output;
    // std::getline(input,output);
    // cout<<output;

    return 0;
}
