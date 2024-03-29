// 01 一维数组指针.c : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include "pch.h"
#define  _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
void printArray(int arr[],int len)
{
	int i;
	for (i=0;i<len;++i)
	{
		printf("%d\n",arr[i]);
	}
}
void test01(void)
{
	int arr[5] = {1,2,3,4,5};
	//一维数组是不是指针
	printf("%d\n", sizeof arr);
	//除了两种特殊情况下，一维数组名称都是指针首元素的地址
	//特殊情况1：对数组名称进行sizeof
	//特殊情况2：对数组名称取地址
	//int *p = &arr;
	printf("%d\n", &arr);
	printf("%d\n", &arr+1);
	int *p = arr;
	//数组名称是一个指针常量，指针的指向不能修改int * const p;
	
	//arr = null;
	//arr[0] = 100;

	int len = sizeof(arr) / sizeof(arr[0]);
	printArray(arr,len);

	p =p + 3;
	//[]里可以可以放负数-->可以
	printf("%d\n", p[-1]);
	printf("%d\n", *(p - 1));

}
int main()
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
}