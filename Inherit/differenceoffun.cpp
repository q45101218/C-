/*************************************************************************
	> File Name: differenceoffun.cpp
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Mon 18 Dec 2017 10:34:32 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class B
{
public:
    virtual void fun()
    {
        cout<<"B::fun()"<<endl;
    }

    virtual void fun(int x)
    {
        cout<<"B::fun(x=10)"<<endl;
    }
};

class D:public B
{
public:
    virtual void fun(int x)
    {
        cout<<"D::fun(x=20)"<<endl;
    }
};

int main()
{
    D d;
    D* pd=&d;
    B* pb=&d;
    pd->fun(10);
    pd->B::fun();
    pb->fun();
    return 0;
}
