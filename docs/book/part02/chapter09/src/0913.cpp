#include<iostream>
#include<list>
#include<vector>

using std::vector;
using std::list;
using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
    list<int> lint{1,2,3,4,5};
    vector<double> dvec;

    list<int>::iterator liter;

    for(liter=lint.begin();liter!=lint.end();liter++)
    {
        dvec.push_back(*liter);
    }

    cout<<"List:"<<endl;
    for(int e:lint) cout<<e<<" ";
    cout<<endl;

    cout<<"Vector<double>"<<endl;
    for(double e:dvec) cout<<e<<" ";
    cout<<endl;


    vector<double> dvec1;
    vector<int> ivec{6,7,8,9,10};
    vector<int>::iterator iter;

    for (iter=ivec.begin(); iter!=ivec.end(); iter++)
    {
        dvec1.push_back(*iter);
    }

    cout<<"Vector<int>"<<endl;
    for(int e:ivec) cout<<e<<" ";
    cout<<endl;

    cout<<"Vector<double>"<<endl;
    for(int e:dvec1) cout<<e<<" ";
    cout<<endl;
    

    return 0;
}
