// 04 动态库测试.c : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include "pch.h"
#define  _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#pragma  comment(lib,"mydll.lib")
int main()
{
	int ret=mySub(30, 10);
	printf("%d\n", ret);
	system("pause");
	return EXIT_SUCCESS;
}