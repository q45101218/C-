/*************************************************************************
	> File Name: Stringcow.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 26 Oct 2017 08:34:14 AM PDT
 ************************************************************************/

#include<iostream>
#include<string.h>
using namespace std;

class Stringcow
{
public:
    Stringcow(const char* ptr="")
    :_str(new char[strlen(ptr)+5])
    {
        *(int*)_str=1;
        strcpy(_str+4,ptr);
    }

    Stringcow(const Stringcow& s)
    :_str(s._str)
    {
        (*(int*)_str)++;
    }

    Stringcow& operator=(const Stringcow& s)
    {
        if(_str!=s._str)
        {
            release();
            _str=s._str;
            (*(int*)_str)++;
        }
        return *this;
    }

    ~Stringcow()
    {
        release();
    }

    void release()
    {
        if(--(*(int*)_str)==0)
        {
            delete[] _str;
            _str=NULL;
        }
    }

    void Print()
    {
       cout<<(_str+4)<<endl; 
    }
private:
    char* _str;
};
