// 03 静态库测试.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include "pch.h"
#define  _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "mylib.h"
void test01(void)
{
	printf("%d\n", add(10, 20));
}
int main()
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
}