/*************************************************************************
	> File Name: String.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 25 Oct 2017 07:37:48 PM PDT
 ************************************************************************/

#include<iostream>
#include<string.h>
using namespace std;

class String
{
public:
    String(const char* ptr="")
    :_sptr(new char [strlen(ptr)+1])
    {
        strcpy(_sptr,ptr);
    }

    String(const String& s)
    :_sptr(new char [strlen(s._sptr)+1])
    {
        strcpy(_sptr,s._sptr);
    }

    String& operator=(String s)
    {
        swap(_sptr,s._sptr);
        return *this;
    }

    ~String()
    {
        if(NULL!=_sptr)
        {
            delete[] _sptr;
            _sptr=NULL;
        }
    }

    size_t Size()const
    {
       strlen(_sptr);
    }

    size_t Length()const
    {
        strlen(_sptr);
    }

    void Print()const
    {
        cout<<_sptr<<endl;
    }
private:
    char* _sptr;
};
