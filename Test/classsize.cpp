/*************************************************************************
	> File Name: classsize.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 01 Nov 2017 12:44:11 AM PDT
 ************************************************************************/

#include<iostream>
using namespace std;
class AA
{
    char a;
    short b;
}; 

class A
{
    int A_a;
    char A_b;
};

class B:public A
{
    char B_a;
};

class C:public B
{
    char C_a;
};

//other class which datatypes are the same as C

class D
{
    int a;
    char b;
    char c;
    char d;
};

int main()
{  
    cout<<sizeof(AA)<<endl; 
    cout<<sizeof(B)<<endl; 
    cout<<sizeof(C)<<endl; 
    cout<<sizeof(D)<<endl;
    return 0;
}
