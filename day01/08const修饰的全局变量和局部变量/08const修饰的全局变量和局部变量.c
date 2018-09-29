// 08const修饰的全局变量和局部变量.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include "pch.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//const修饰的全局变量,即使语法通过，但是运行时受到常量区的保护，运行失败
const int a = 100;
void test01()
{
	//a = 200;
	int *p = &a;
	*p = 300;
	printf("%d\n",a);
}
//const修饰的局部变量
void test02(void)
{
	const int b = 10;//分配到栈上
	//b = 100;//直接修改失败
	//间接修改成功
	//c语言下，成为伪常量
	int *p = &b;
	*p = 100;
	printf("%d\n",b);
	//int a[b];//伪常量是不可以初始化数组的
}

int main()
{
	//test01();
	test02();
	return 0;
}
