/*************************************************************************
	> File Name: classnomalinherit.cpp
	> Author:Yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Sat 25 Nov 2017 03:13:47 PM CST
 ************************************************************************/

#include<iostream>
#include"printvirtable.hpp"
using namespace std;


class A
{
public:
    virtual void A1()
    {
        cout<<"A::A1()"<<endl;
    }
    virtual void A2()
    {
        cout<<"A::A2()"<<endl;
    }
};

class B:public A
{
public:
    virtual void A1()
    {
        cout<<"B::A1()"<<endl;
    }

    virtual void B1()
    {
        cout<<"B::B1()"<<endl;
    }
};


int main()
{
    A a;
    B b;
    int** ptra=(int**)(*(int**)&a);
    int** ptr1=(int**)(*(int**)&b);
    //print(ptra);
    print(ptr1);
    return 0;
}
