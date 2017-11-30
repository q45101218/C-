/*************************************************************************
	> File Name: test.cpp
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Thu 30 Nov 2017 07:09:27 PM CST
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include"commentconversion.hpp"
using namespace std;


int main()
{
    CommentConversion c("input.c", "output.c");
    c.start();
    return 0;
}


