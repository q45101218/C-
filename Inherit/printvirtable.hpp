/*************************************************************************
	> File Name: printvirtable.hpp
	> Author:Yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Sat 25 Nov 2017 03:14:48 PM CST
 ************************************************************************/

#pragma once
#include<iostream>
#include<stdio.h>
using namespace std;

typedef void (*p) (void);
void print(int** ptr)
{

    int index=0;
    for(;ptr[index]!=NULL;index++)
    {
        printf("virtual table [%d]:%p-->",index,ptr[index]);
        p fun=(p)(ptr[index]);
        fun();
    }
}
