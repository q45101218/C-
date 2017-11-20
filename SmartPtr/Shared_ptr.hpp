/*************************************************************************
	> File Name: Shared_ptr.h
	> Author:YangKun 
	> Mail:yangkungetit@163.com 
	> Created Time: Sat 18 Nov 2017 02:25:33 PM PST
 ************************************************************************/
#pragma once
#include"Weak_ptr.hpp"
#include<assert.h>
template<class T>
class Shared_ptr
{
public:
    Shared_ptr(T* const& ptr=NULL)
    :_ptr(ptr)
    ,_refcount(new int(1))
    {}

    Shared_ptr(const Shared_ptr<T>& sp)
    :_ptr(sp._ptr)
    ,_refcount(sp._refcount)
    {
        (*_refcount)++;
    }

    Shared_ptr<T>& operator=(const Shared_ptr<T>& sp)
    {
        if(_ptr!=sp._ptr)
        {
            Release();
            _ptr=sp._ptr;
            _refcount=sp.refcount;
            (*_refcount)++;
        }
        return *this;
    }

    ~Shared_ptr()
    {
        Release();
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
    void Release()
    {
        if(--(*_refcount)==0)
        {
            if(_ptr!=NULL)
            {
                delete _ptr;
            }
            delete _refcount;
            _ptr=NULL;
            _refcount=NULL;
        }
    }
private:
    T* _ptr;
    int* _refcount;
};
