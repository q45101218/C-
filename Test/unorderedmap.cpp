/*************************************************************************
	> File Name: unorderedmap.cpp
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Mon 18 Dec 2017 11:25:33 AM CST
 ************************************************************************/

#include<iostream>
#include<unordered_map>
using namespace std;

int main()
{
    unordered_map<int,int> mp;
    mp.insert(make_pair(1,1));
    mp.insert(make_pair(2,1));
    mp.insert(make_pair(3,1));
    mp.insert(make_pair(4,1));
    mp.insert(make_pair(5,1));
    if(mp.find(1)!=mp.end())
    {
        cout<<"hello world"<<endl;
    }
    return 0;
}

