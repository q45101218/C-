/*************************************************************************
	> File Name: doubleparent.cpp
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Tue 28 Nov 2017 02:15:41 PM CST
 ************************************************************************/

#include<iostream>
#include"printvirtable.hpp"
using namespace std;

class A
{
public:
    virtual void a1()
    {
        cout<<"A::a1()"<<endl;
    }

    virtual void a2()
    {
        cout<<"A::a2()"<<endl;
    }
};

class B
{
public:
    virtual void a1()
    {
        cout<<"B::a()"<<endl;
    }

    virtual void a2()
    {
        cout<<"B::a2"<<endl;
    }
};

class C:public A,B
{
    virtual void a1()
    {
        cout<<"C::a1()"<<endl;
    }

    virtual void c1()
    {
        cout<<"C::c1()"<<endl;
    }
};

int main()
{
    C c;
    A* ptra=&c;
    int** ptr1=(int**)(*(int**)(ptra));
    print(ptr1);
    return 0;
}

