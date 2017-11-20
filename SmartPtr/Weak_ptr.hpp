/*************************************************************************
	> File Name: Weak_ptr.h
	> Author:YangKun 
	> Mail:yangkungetit@163.com 
	> Created Time: Sun 19 Nov 2017 10:19:37 PM PST
 ************************************************************************/

#pragma once

template<class T>
class Weak_ptr
{
public:
    Weak_ptr(const T* ptr=NULL)
    :_ptr(ptr)
    {}

    Weak_ptr(const Shared_ptr<T>& sp)
    :_ptr(sp._ptr)
    {}

private:
    T* _ptr;
};
