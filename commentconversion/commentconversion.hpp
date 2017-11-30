/*************************************************************************
	> File Name: commentconversion.hpp
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Thu 30 Nov 2017 07:04:55 PM CST
 ************************************************************************/

#pragma once

#include<iostream>
#include<assert.h>
using namespace std;

enum condition
{
    Fallow,        //无状态标志 
    C_scope,       //C注释状态标志
    Cpp_scope,     //C++注释状态标志
    Exit,          //退出状态标志
};

class CommentConversion
{
public:
    CommentConversion(const char* srcfilename, const char* desfilename);

    void start();           //开始，并进行个状态的转换调用函数

    void Fallowscope();     //无状态是调用函数

    void Cscope();          //c注释下调用状态函数

    void Cppscope();        //C++注释下调用函数

    void Copy();            //直接拷贝功能

    bool EndofFile();       //判断文件是否读完

    ~CommentConversion();   //关闭文件

private:
    condition status;
    FILE* src;
    FILE* des;
};

inline CommentConversion::CommentConversion(const char* srcfilename, const char* desfilename)
    :status(Fallow)
{
    assert(srcfilename);
    assert(desfilename);

    assert(src=fopen(srcfilename, "r"));
    printf("open output file successfully.\n");
    assert(des=fopen(desfilename, "w"));
    printf("open input file successfully.\n");
}

inline void CommentConversion::start()
{
    while (status != Exit)
    {
        switch (status)
        {
        case Fallow:
            Fallowscope();
            break;
        case C_scope:
            Cscope();
            break;
        case Cpp_scope:
            Cppscope();
            break;
        default:
            break;
        }
    }
}

inline void CommentConversion::Fallowscope()
{
    while (1)
    {
        if (EndofFile())
            break;

        char first = fgetc(src);
            
        if (first=='/')
        {
            char second = fgetc(src);

            if (second == '*')
            {
                second = '/';
                status = C_scope;
                fputs("//", des);
                break;
            }
            if (second == '/')
            {
                status = Cpp_scope;
                fputs("//", des);
                break;
            }
        }
        fputc(first, des);
    }
}

inline void CommentConversion::Cscope()
{
    char first;
    while (1)
    {
        if (EndofFile())
            break;

        first = fgetc(src);
        if (first == '*')
        {
            char second = fgetc(src);
            if (second == '/')
            {
                status = Fallow;
                first = fgetc(src);
                if (first != '\n')           //判断是否需要换行，first为换行，则无需重复添加
                    fputc('\n', des);
                fseek(src, -1, SEEK_CUR);   //此时文件的位置位于C注释结束下一个位置，需要重置回去
                
                break;
            }
            fseek(src, -1, SEEK_CUR);       //同理
            fputc(first, des);
        }
        else if (first == '\n')
        {
            fputc(first, des);
            fputs("//", des);
        }
        else
        {
            fputc(first, des);
        }
    }
}

inline void CommentConversion::Cppscope()
{
    while (1)
    {
        if (EndofFile())
            break;
        char first = fgetc(src);
        if (first == '\n')
        {
            status = Fallow;
            fputc(first, des);
            break;
        }
        else if (first == '/')
        {
            char second = fgetc(src);
            if (second == '/')
                continue;
            fputc(first, des);
            fputc(second, des);
        }
        else
        {
            fputc(first, des);
        }
    }
}

CommentConversion::~CommentConversion()
{
    fclose(src);
    fclose(des);
}

void CommentConversion::Copy()
{
    while (1)
    {
        if (EndofFile())
            break;
        char first = fgetc(src);
        char second = fgetc(src);
        fputc(first, des);
        fputc(second, des);
    }
}

bool CommentConversion::EndofFile()
{
    if (feof(src))
    {
        status = Exit;
        return true;
    }
    return false;
}
