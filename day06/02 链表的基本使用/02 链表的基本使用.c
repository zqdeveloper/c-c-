// 02 链表的基本使用.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include "pch.h"
#define  _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "linkList.h"
void test01(void)
{
	struct LinkNode *pHeader = init_linkList();
	foreach_linkList(pHeader);
}
int main()
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
