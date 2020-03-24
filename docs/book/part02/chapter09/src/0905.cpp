#include<iostream>
#include<vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

vector<int>::iterator
FindTarget(
    vector<int>::iterator begin,
    vector<int>::iterator end,
    int target){

        while (begin!=end)
        {
            if(*begin==target)
                return begin;
            begin++;
        }
        return end;
}

int main(int argc, char const *argv[])
{
    vector<int> numbers;
    vector<int>::iterator begin;
    vector<int>::iterator end;

    int target;
    int elem;
    int result;

    begin=numbers.begin();
    end=numbers.end();

    cout<<"Enter some integers"<<endl;
    while (cin>>elem)
    {
        numbers.push_back(elem);
        if(cin.get()=='\n')
            break;
    }
    
    if(!numbers.empty())
    {
        cout<<"Enter your target number"<<endl;
        cin>>target;


        
    }else
    {
        std::cerr<<"Vector is empty"<<endl;
    }
    
    return 0;
}
