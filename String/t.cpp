/*************************************************************************
	> File Name: t.cpp
	> Author:YangKun 
	> Mail:yangkungetit@163.com 
	> Created Time: Tue 07 Nov 2017 03:04:59 PM PST
 ************************************************************************/

#include<iostream>
using namespace std;
int main()
{
    const char* p="asd";
    cout<<sizeof(p)<<endl;
    (int*)p;
    cout<<sizeof(p)<<endl;
    return 0;
}
