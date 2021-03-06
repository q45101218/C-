/*************************************************************************
	> File Name: Scoped_ptr.h
	> Author:YangKun 
	> Mail:yangkungetit@163.com 
	> Created Time: Sat 18 Nov 2017 01:50:54 PM PST
 ************************************************************************/
#pragma once
#include<assert.h>
template<class T>
class Scoped_ptr
{
public:
    Scoped_ptr(T* const& ptr=NULL)
    :_ptr(ptr)
    {}

    ~Scoped_ptr()
    {
        if(_ptr)
        {
            delete _ptr;
            _ptr=NULL;
        }
    }

    T* operator->()
    {
        assert(_ptr);
        return _ptr;
    }

    T& operator*()
    {
        assert(_ptr);
        return *_ptr;
    }

private:
    Scoped_ptr(const Scoped_ptr<T>&);
    Scoped_ptr<T>& operator=(const Scoped_ptr<T>&);

private:
    T* _ptr;
};
