/*************************************************************************
	> File Name: TypeTraits.cpp
	> Author:YangKun 
	> Mail:yangkungetit@163.com 
	> Created Time: Thu 16 Nov 2017 09:31:16 PM PST
 ************************************************************************/

#include<iostream>
#include<string.h>
using namespace std;


struct __TrueType{};
struct __FalseType{};

template<class T>
struct TypeTraits
{
    typedef __FalseType __isPOD;
};

template<>
struct TypeTraits<int>
{
    typedef __TrueType __isPOD;
};

template<>
struct TypeTraits<char>
{
    typedef __TrueType __isPOD;
};

template<>
struct TypeTraits<double>
{
    typedef __TrueType __isPOD;
};

template<>
struct TypeTraits<float>
{
    typedef __TrueType __isPOD;
};

template<>
struct TypeTraits<size_t>
{
    typedef __TrueType __isPOD;
};


template<class T>
T* _Copy(T* dest,T* src,size_t size,__TrueType) 
{
    return (T*)memcpy(dest,src,size);
}

template<class T>
T* _Copy(T* dest,T* src,size_t size,__FalseType) 
{
    for(int i=0;i<size;i++)
    {
        dest[i]=src[i];
    }
    return dest;
}

template<class T>
T* Copy(T* dest,T* src,size_t size)
{
    return _Copy<T>(dest,src,size,TypeTraits<T>::__isPOD());
}

int main()
{
    char p1[]="12345";
    char p2[]="98765";
    Copy<char>(p1,p2,strlen(p1));
    return 0;
}
