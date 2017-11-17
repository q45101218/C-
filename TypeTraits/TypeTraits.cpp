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
struct TypeTraits
{
    typedef __FalseType __isPOD;
};

template<class T>
T* _Copy(void* dest,const void* src,size_t size,__TrueType) 
{
    return (T*)memcpy(dest,src,size);
}

template<class T>
T* _Copy(void* dest,const void* src,size_t size,__FalseType) 
{
    T* d=(T*)dest;
    T* s=(T*)src;
    for(int i=0;i<size;i++)
    {
        d[i]=s[i];
    }
    return (T*)dest;
}

template<class T>
T* Copy(void* dest const void* src,size_t size)
{
    return _Copy(dest,src,size,TypeTraits::__isPOD);
}

int main()
{
    char p1="12345";
    char p2="98765";
    Copy(p1,p2,strlen(p1));
    retrun 0;
}
