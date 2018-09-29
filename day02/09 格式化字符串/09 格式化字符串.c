// 09 格式化字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>
void test01(void)
{

	char buf[1024];
	memset(buf,0,1024);
	sprintf(buf,"今天是%d年%d月%d日",2018,5,6);
	printf("%s\n",buf);
	memset(buf, 0, 1024);
	//字符串拼接
	char str1[] = "hello";
	char str2[] = "world";
	int len=sprintf(buf, "%s%s",str1,str2);
	printf("%s\t%d\n", buf,len);
	//数字变成字符串
	memset(buf, 0, 1024);
	int num = 100;
	sprintf(buf, "%d",num);
	printf("%s\n", buf);

	//设置宽度右对齐
	memset(buf,0,1024);
	sprintf(buf,"%8d",num);
	printf("%s\n", buf);
	//设置宽度左对齐
	memset(buf, 0, 1024);
	sprintf(buf, "%-8d", num);
	printf("%s\n", buf);
	//转成16进制字符串小写
	memset(buf, 0, 1024);
	sprintf(buf, "0x%x", num);
	printf("%s\n", buf);
	//转成8进制字符串
	memset(buf, 0, 1024);
	sprintf(buf, "0%o", num);
	printf("%s\n", buf);
}
int main()
{
	test01();
	return 0;
}
