/*************************************************************************
	> File Name: Scoped_array.h
	> Author:YangKun 
	> Mail:yangkungetit@163.com 
	> Created Time: Sat 18 Nov 2017 02:16:21 PM PST
 ************************************************************************/

#pragma once
#include<assert.h>
template<class T>
class Scoped_array
{
public:
    Scoped_array(T* const& ptr=NULL)
    :_ptr(ptr)
    {}

    ~Scoped_array()
    {
        if(_ptr)
        {
            delete[] _ptr;
            _ptr=NULL;
        }
    }

    T& operator[](size_t pos)
    {
        assert(_ptr);
        return _ptr[pos];
    }

private:
    Scoped_array(const Scoped_array<T>&);
    Scoped_array<T>& operator=(const Scoped_array<T>&);
private:
    T* _ptr;
};
