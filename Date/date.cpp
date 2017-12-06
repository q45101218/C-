/*************************************************************************
	> File Name: date.cpp
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Wed 06 Dec 2017 01:38:51 PM CST
 ************************************************************************/

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string>
#include<assert.h>
using namespace std;

class date
{
    friend ostream& operator<<(ostream& in,const date& d);
public:
    date(int year=1400,int month=1,int day=1)
    :_year(year)
    ,_month(month)
    ,_day(day)
    {
        checklegal(_year,_month,_day);
    }

    bool checklegal(int year,int month,int day)
    {
        if(year<0 ||month<0 ||month>12||day<0||day>Days_in_monthofyear(year,month))
            perror("date legal");
    }

    int Days_in_monthofyear(int year,int month)
    {
        static int getdays[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
        if(month==2)
        {
            if(((year%4==0)&&(year%100!=0))||(year%400==0))
                return getdays[month]+1;
        }
        return getdays[month];
    }

    date& operator++();

    date operator++(int);

    date& operator--();

    date operator--(int);

    date& operator+(int days);

    date& operator+=(int days);

    date& operator-(int days);

    date& operator-=(int days);

    int operator-(const date& d);

private:
    int _day;
    int _month;
    int _year;
};

ostream& operator<<(ostream& in,const date& d)
{
    in<<d._year<<"-"<<d._month<<"-"<<d._day<<endl;
    return in;
}


int main()
{
    date d;
    cout<<d<<endl;
    date d2(2001,2,29);
    return 0;
}
