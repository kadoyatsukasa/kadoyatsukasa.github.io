#include<iostream>
#include<string>
#include<list>
#include<vector>

using std::endl;
using std::cout;
using std::cin;
using std::vector;
using std::list;
using std::string;

int main(int argc, char const *argv[])
{
    list<char*> clist;
    clist.push_back("hello");
    clist.push_back("world");

    vector<string> svec;

    // for(list<char*>::iterator citer=clist.begin();citer!=clist.end();citer++)
    //     svec.push_back(*citer);

    for(char* e:clist)
        svec.push_back(e);
    
    for(string e:svec)
        cout<<e<<" ";
    
    return 0;
}
