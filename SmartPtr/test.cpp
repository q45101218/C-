/*************************************************************************
	> File Name: test.cpp
	> Author:YangKun 
	> Mail:yangkungetit@163.com 
	> Created Time: Sat 18 Nov 2017 01:24:40 PM PST
 ************************************************************************/

#include<iostream>
#include"Auto_ptr.hpp"
#include"Scoped_ptr.hpp"
using namespace std;

int main()
{
    Auto_ptr<int> p1(new int(1));
    Auto_ptr<int> p2=p1;

    Scoped_ptr<char> p3(new char(1));
    //Scoped_ptr<char> p4=p3;
    return 0;
}




