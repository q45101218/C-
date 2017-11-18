/*************************************************************************
	> File Name: Shared_array.h
	> Author:YangKun 
	> Mail:yangkungetit@163.com 
	> Created Time: Sat 18 Nov 2017 02:54:38 PM PST
 ************************************************************************/
#pragma once

#include<assert.h>
template<class T>
class Shared_array
{
public:
    Shared_array(T* const& ptr=NULL)
    :_ptr(ptr)
    ,_refcount(new int(1))
    {}

    Shared_array(const Shared_array<T>& sp)
    :_ptr(sp._ptr)
    ,_refcount(sp.refcount)
    {
        (*_refcount)++;
    }

    Shared_array<T>& operator=(const Shared_array<T>& sp)
    {
        if(sp._ptr!=_ptr)
        {
            Release();
            _ptr=sp._ptr;
            _refcount=sp.refcount;
            (*_refcount)++;
        }
        return *this;
    }

    ~Shared_array()
    {
        Release();
    }

private:
    void Release()
    {
        if(--(*_refcount)==0)
        {
            if(_ptr)
            {
                delete[] _ptr;
                delete _refcount;
            }
            _ptr=NULL:
            _refcount=NULL;
        }
    }

private:
    T* _ptr;
    int* _refcount;
};
