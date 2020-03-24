#include<iostream>
#include<vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

bool FindTarget(
    vector<int>::iterator begin,
    vector<int>::iterator end,
    int target){
    
    while (begin!=end)
    {
        if(*begin==target) return true;
        begin++;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    vector<int> numbers;
    vector<int>::iterator begin;
    vector<int>::iterator end;

    int elem;
    int target;
    
    cout<<"Enter some integers(q to quit)"<<endl;

    while (cin>>elem)
    {
        numbers.push_back(elem);
        if(cin.get()=='\n')
            break;
    }

    if(!numbers.empty()){
        cout<<"Enter the number you want to find"<<endl;
        cin>>target;
        begin=numbers.begin();
        end=numbers.end();

        if(FindTarget(begin,end,target))
            cout<<"Got it"<<endl;
        else
            cout<<"Can't find the target"<<endl;
    }
    else
    {
        std::cerr<<"Vetor is empty"<<endl;
    }
    
    
    return 0;
}
