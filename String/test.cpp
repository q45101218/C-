/*************************************************************************
	> File Name: test.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 25 Oct 2017 07:54:34 PM PDT
 ************************************************************************/

#include<iostream>
#include"String.hpp"
using namespace std;


int main()
{
    String s1("1111111");
    s1.Print();
    String s2("2222222");
    s2.Print();
    String s3(s1);
    s3.Print();
    s3=s2;
    s3.Print();
    return 0;
}

