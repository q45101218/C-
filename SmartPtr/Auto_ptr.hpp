/*************************************************************************
	> File Name: Auto_ptr.h
	> Author:YangKun 
	> Mail:yangkungetit@163.com 
	> Created Time: Sat 18 Nov 2017 01:15:10 PM PST
 ************************************************************************/
#pragma once

#include<iostream>
#include<assert.h>
template<class T>
class Auto_ptr
{
public:
    Auto_ptr(T* const& ptr=NULL)
    :_ptr(ptr)
    {}

    Auto_ptr(Auto_ptr<T>& ap)
    :_ptr(ap._ptr)
    {
        ap._ptr=NULL;
    }

    Auto_ptr<T>& operator=(Auto_ptr<T>& ap)
    {
        if(this!=&ap)
        {
            if(_ptr!=NULL)
            {
                delete _ptr;
            }
            _ptr=ap._ptr;
            ap._ptr=NULL;
        }
        return *this;
    }

    ~Auto_ptr()
    {
        if(_ptr!=NULL)
        {
            delete _ptr;
        }
    }

    T& operator*()
    {
        assert(_ptr);
        return *_ptr;
    }

    T* operator->()
    {
        assert(_ptr);
        return _ptr;
    }
private:
    T* _ptr;
};


