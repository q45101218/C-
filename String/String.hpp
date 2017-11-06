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
    String(const char* str="")
    :_size(strlen(str))
    ,_capacity(size)
    ,_str(new char [capacity+1])
    {
        strcpy(_str,str);
    }

    String(const String& s)
    :_size(strlen(s._size))
    ,_capacity(_size)
    ,_str(new char [_capacity+1])
    {
        strcpy(_str,s._str);
    }

    //string(const String& s)
    //:_size(0)
    //,_capacity(0)
    //,_str(NULL)
    //{
    //      String tmp(s._str);
    //      Swap(tmp);
    //}

    String& operator=(String s)
    {
        swap(_capacity,s._capacity);
        swap(_size,s._size);
        swap(_str,s._str);
        //Swap(s);
        return *this;
    }

    ~String()
    {
        if(NULL!=_str)
        {
            delete[] _str;
            _str=NULL;
        }
    }


    char* Getstr()
    {
        return _str;
    }

    void Swap(String& s)
    {
        swap(_size,s._size);
        swap(_capacity,s._capacity);
        swap(_str,s._str);
    }

    size_t Size()const
    {
       return _size;
    }

    size_t Length()const
    {
        return _size;
    }

    void Expand(size_t n)
    {
        if(n>_capacity)
        {
            char* tmp=new char[n+1];
            strcpy(tmp,_str);
            delete[] _str;
            _str=tmp;
            _capacity=n;
        }
    }

    void Print()const
    {
        cout<<_str<<endl;
    }
private:
    char* _str;
    size_t _size;
    size_t _capacity;
};
