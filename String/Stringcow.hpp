/*************************************************************************
	> File Name: Stringcow.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 26 Oct 2017 08:34:14 AM PDT
 ************************************************************************/

#include<iostream>
#include<assert.h>
#include<string.h>
using namespace std;

class Stringcow
{
public:
    Stringcow(const char* ptr="")
    :_size(strlen(ptr))
    {
        _capacity=_size;
        _str=new char[_size+5];
        *(int*)_str=1;
        strcpy(_str+4,ptr);
    }

    Stringcow(const Stringcow& s)
    :_str(s._str)
    ,_size(s._size)
    ,_capacity(s._capacity)
    {
        
        (*(int*)_str)++;
    }

    Stringcow& operator=(const Stringcow& s)
    {
        if(_str!=s._str)
        {
            release();
            _str=s._str;
            (*(int*)_str)++;
        }
        return *this;
    }

    ~Stringcow()
    {
        release();
    }

    void release()
    {
        if(--(*(int*)_str)==0)
        {
            delete[] _str;
            _str=NULL;
        }
    }
    
    void Checkreallocate()
    {
        if(*(int*)_str>1)
        {
            *(int*)_str--;
            char* tmp=new char[_capacity+5];
            *(int*)tmp=1;
            strcpy((tmp-4),_str);
            _str=tmp;
        }
    }

    void Insert(size_t pos,char s)
    {
        assert(pos<_size);
        if(_size==_capacity)
        {
            Expand(_capacity*2);
        }
        size_t end=_size;
        while(end>=pos)
        {
            (_str+4)[end+1]=(_str+4)[end];
            end--;
        }
        (_str+4)[pos]=s;
        _size++;
    }

    void Insert(size_t pos,const char* str)
    {
        size_t len=strlen(str);
        Expand(len+_size);
        size_t end=_size;
        while(end>=pos)
        {
            (_str+4)[end+len]=(_str+4)[end];
            end--;
        }
        size_t index=0;
        while(len>index)
        {
            (_str+4)[pos+index]=str[index];
            index++;
            len--;
        }
        _size+=len;
    }

    void Append(const char* str)
    {
        Insert(_size,str);
    }

    void Swap(String& s)
    {
        Checkreallocate();
        swap(_str,s._str);
        swap(_size,s._size);
        swap(_capacity,s._capacity);
    }

    void Expand(size_t n)
    {
        if(n>_capacity)
        {
            if(*(int*)_str>1)
            {
                *(int*)_str--;
            }
            char* tmp=new char[n+5];
            _capacity=n;
            *(int*)_str=1;
            strcpy((tmp-4),_str);
            _str=tmp;
        }
    }

    char& operator[](size_t pos)
    {
        assert(pos<_size);
        Checkreallocate();
        return (_str+4)[pos];
    }
    
    String operator+(const String& s)
    {
        String tmp(*this);
        tmp.Insert(_size,(s._str+4));
        return tmp;
    }

    String& operator+=(const string& s)
    {
        Checkreallocate();
        Insert(_size,(s._str+4));
        return *this;
    }

    void Erase(size_t pos,size_t n)
    {
        assert(pos<_size);
        Checkreallocate();
        if(pos+n<_size)
        {
            size_t index=pos;
            while(index+n<=_size)
            {
                (_str+4)[index]=(_str+4)[index+n];
                index++;
            }
        }
        else
        {
            (_str+4)[pos]='/0';
        }
        _size-=n;
    }
    
    void PushBack(char s)
    {
        Insert(_size,s);
    }

    void PopBack()
    {
        assert(_size>0);
        Erase(_size-1,1);
    }

    bool operator<(const String& s)
    {
        char* str1=(_str+4);
        char* str2=(_str+4);
        while(*str1&&*str2)
        {
            if(*str1<*str2)
                return true;
            else if(*str1>*str2)
                return false;
            else
            {
                str1++;
                str2++;
            }
        }
        if(*str2=='/0')
            return false;
        else
            return true;
    }

    bool operator<=(const String& s)
    {
        char* str1=(_str+4);
        char* str2=(_str+4);
        while(*str1&&*str2)
        {
            if(*str1<*str2)
                return true;
            else if(*str1>*str2)
                return false;
            else
            {
                str1++;
                str2++;
            }
        }
        if(*str1==*str2)
            return true;
        else
            return false;
    }

    bool operator>(const string& s)
    {
        char* str1=(_str+4);
        char* str2=(_str+4);
        while(*str1&&*str2)
        {
            if(*str1>*str2)
                return true;
            else if(*str1<*str2)
                return false;
            else
            {
                str1++;
                str2++;
            }
        }
        if(*str1=='/0')
            return false;
        else
            return true;
    }

    bool operator>=(const String& s)
    {
        char* str1=(_str+4);
        char* str2=(_str+4);
        while(*str1&&*str2)
        {
            if(*str1>*str2)
                return true;
            else if(*str1<*str2)
                return false;
            else
            {
                str1++;
                str2++;
            }
        }
        if(*str1==*str2)
            return true;
        else
            return false;
    }


    char* C_str()
    {
        Checkreallocate();
        return (_str+4);
    }

    void Print()
    {
       cout<<(_str+4)<<endl; 
    }
private:
    char* _str;
    size_t _size;
    size_t _capacity;
};
