/*************************************************************************
	> File Name: test.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 25 Oct 2017 07:54:34 PM PDT
 ************************************************************************/

#include<iostream>
#include<string.h>
#include"Stringcow.hpp"
using namespace std;


int main()
{
    Stringcow s1("1111111");
    s1.Print();
    Stringcow s2("2222222");
    s2.Print();
    Stringcow s3(s1);
    s3.Print();
    s3=s2;
    s3.Print();
    return 0;
}

