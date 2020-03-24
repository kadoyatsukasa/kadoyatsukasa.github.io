#ifndef _BOOK_CONTROLLER_H_
#define _BOOK_CONTROLLER_H_

#include "personInfo.h"

class BookController{
    public: 
    void savePersonInfoIntoVector(PersonInfo& ,vector<PersonInfo>);

    private:
    PersonInfo info;
};

#endif