/*************************************************************************
	> File Name: String.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 25 Oct 2017 07:37:48 PM PDT
 ************************************************************************/

#include<iostream>
#include<string.h>
#include<assert.h>
#include<string>
using namespace std;

class String
{
public:
    String(const char* str="")
    :_size(strlen(str))
    {
        _capacity=_size;
        _str=new char[_capacity+1];
        strcpy(_str,str);
    }

    String(const String& s)
    :_size(s._size)
    ,_capacity(s._capacity)
    ,_str(new char[s._capacity+1])
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

    void Insert(size_t pos,char s)
    {
        assert(pos<=_size);
        if(_size==_capacity)
        {
            Expand(_capacity*2);
        }
        size_t end=_size;

        while(end>=pos)
        {
            _str[end+1]=_str[end];
            end--;
        }
        _str[pos]=s;
        _size++;
    }

    void Insert(size_t pos,const char* str)
    {
        assert(pos<=_size);
        size_t len=strlen(str);
        Expand(_size+len);
        size_t end=_size;
        while(end>=pos)
        {
            _str[end+len]=_str[end];
            end--;
        }
        size_t index=0;
        while(index<len)
        {
            _str[pos+index]=str[index];
            index++;
            pos++;
        }
        _size+=len;
    }

    void Append(const char* str)
    {
        Insert(_size,str);
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

    char& operator[](size_t pos)
    {
        assert(pos<_size);
        return _str[pos];
    }

    String& operator+=(const String& s)
    {
        Append(s._str);
        return *this;
    }

    String operator+(const String& s)
    {
        String tmp(_str);
        tmp.Append(s._str);
        return tmp;
    }

    void Erase(size_t pos,size_t n)
    {
        assert(pos<_size);
        if(pos+n>=_size)
        {
            _str[pos]='\0';
            _size=pos;
        }
        else
        {
            size_t index=pos+n;
            while(index<=_size)
            {
                _str[pos]=_str[index];
                pos++;
                index++;
            }
            _size-=n;
        }
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

    bool operator>(const String& s)const
    {
        char* str1=_str;
        char* str2=s._str;
        while(*str1&&*str2)
        {
            if(*str1>*str)
            {
                return true;
            }
            else if(*str1<*str2)
            {
                return false;
            }
            else
            {
                str1++;
                str2++;
            }
        }
        if(*str1=='\0')
            return false;
        else
        {
            return true;
        }
    }
    
    bool operator>=(const String& s)const
    {
        char* str1=_str;
        char* str2=s._str;
        while(*str1&&*str2)
        {
            if(*str1>=*str2)
                return true;
            else
            {
                str1++;
                str2++;
            }
        }
        return true;
    }
    
    bool operator<(const String& s)const
    {
        char* str1=_str;
        char* str2=s._str;
        while(*str1&&*str2)
        {
            if(*str1<*str2)
            {
                return true;
            }
            else if(*str1>*str2)
            {
                return false;
            }
            else
            {
                str1++;
                str2++;
            }
        }
        if(*str2=='\0')
            return false;
        else
            return true;
    }

    bool operator<=(const String& s)const
    {
        char* str1=_str;
        char* str2=s._str;
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
        return true;
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
