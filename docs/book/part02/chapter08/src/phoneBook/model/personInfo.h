#ifndef _PERSON_INFO_H_
#define _PERSON_INFO_H_

#include<iostream>
#include<sstream>
#include<vector>
#include<string>

using std::vector;
using std::string;
using std::istringstream;
using std::ostringstream;

class PersonInfo{
    friend void savePersonInfoAsVector(PersonInfo& info,vector<PersonInfo> pvect);
    
    public:
    PersonInfo();
    PersonInfo(string,vector<string>);
    
    inline void setName(string name){mName=name;}
    inline void setPhones(vector<string> phones){mPhones=phones;}
    string getName(){return mName;}
    vector<string> getPhones(){return mPhones;}


    private:
    string mName;
    vector<string> mPhones;
};

#endif