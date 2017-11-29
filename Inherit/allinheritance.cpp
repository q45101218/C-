/*************************************************************************
	> File Name: allinheritance.cpp
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Wed 29 Nov 2017 04:02:57 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;


void printvirtualbasetable(int* ptr)
{
    cout << ptr << endl;
    //cout << *(ptr) << endl;
    cout << *(ptr+1) << endl;
}

class A
{
public:
    virtual void a1()
    {
        cout << "A::a1()" << endl;
    }
    virtual void a2()
    {
        cout << "A::a2()" << endl;
    }
};

class B :virtual public A
{
public:
    virtual void b1()
    {
        cout << "B::b1()" << endl;
    }
};

class C :virtual public A
{
public:
    virtual void c1()
    {
        cout << "C::c1()" << endl;
    }
};

class D :public B, public C
{
public:
    virtual void a1()
    {
        cout << "D::a1()" << endl;
    }

    virtual void d1()
    {
        cout << "D::d1()" << endl;
    }
};

//class A
//{
//public:
//  int a;
//};
//
//class B:virtual public A
//{
//public:
//  int b;
//};
//
//class C:virtual public A
//{
//public:
//  int c;
//};
//
//class D:public B,public C
//{
//public:
//  int d;
//};
int main()
{
    D d;
    //d.b = 2;
    //d.c = 3;
    //d.d = 4;
    //d.B::a = 5;
    //d.C::a = 6;
    printvirtualbasetable((int*)*((int*)(&d)+1));
    //printvirtualbasetable((int*)*((int*)(&d)+2));
    ////d.B::a = 5;
    //////d.C::a = 6;
    print((int**)*(int**)(&d));
    //print((int**)*(((int**)(&d)) + 1));
    //print((int**)*(((int**)(&d)) + 4));
    //printvirtualbasetable((int*)*((int*)(&d)));
    //printvirtualbasetable((int*)*((int*)(&d) + 1));
    //printvirtualbasetable((int*)*((int*)(&d) + 3));

    cout << sizeof(d) << endl;
    //print((int**)*(int**)(&d));
    //print((int**)*(int**)(((char*)(&d))+12));

    /*int* ptrb = (int*)*((int*)(&d)+1);
    int* ptrc = (int*)*((int*)(&d)+4);
    printvirtualbasetable(ptrb);
    printvirtualbasetable(ptrc);

    int** vptrb = (int**)*(int**)(&d);
    print(vptrb);
    int** vptrc = (int**)*(int**)(((char*)(&d))+12);
    print(vptrc);
    int** vptra = (int**)*(int**)(((char*)(&d)) +28);
    print(vptra);
    cout << *(int*)(((char*)(&d)) + 8) << endl;
    cout << *(int*)(((char*)(&d)) + 24) << endl;
    cout << *(int*)(((char*)(&d)) + 32) << endl;*/

    return 0;
}
//int main()
//{
//  C c;
//  A* ptra = &c;
//  B* ptrb = &c;
//  int** ptr1 = (int**)(*(int**)(ptra));
//  print(ptr1);
//  int** ptr2 = (int**)(*(int**)(ptrb));
//  c.a = 10;
//  c.b = 20;
//  c.c = 30;
//
//
//  int x = (int)*((int**)(&c) + 1);
//  cout << x << endl;
//
//  printf("%p\n", (int**)(((int**)(&c)) + 1));
//  print(ptr2);
//
//  B b;
//  int** ptr1 = (int**)(*(int**)(&b));
//  int** ptr2 = (int**)(*((int**)(&d) + 2));
//  int** ptr3 = (int**)(*((int**)(&d) + 4));
//  int** ptr4 = (int**)(*((int**)(&d) + 3));
//  print(ptr1);
//  print(ptr2);
//  print(ptr3);
//  print(ptr4);
//  d.a = 10;
//  return 0;
//}

//class A{
//public:
//  int a;
//};
//
//class B :virtual public A
//{
//public:
//  int b;
//};
//
//class C :virtual public A
//{
//public:
//  int c;
//};
//
//class D :public B, public C
//{
//public:
//  int d;
//};
//
//int main()
//{
//  D d;
//  d.a=1;
//  d.b=2;
//  d.c=3;
//  d.d=4;
//  printvirtualbasetable((int*)*(int*)(&d));
//  return 0;
//}
