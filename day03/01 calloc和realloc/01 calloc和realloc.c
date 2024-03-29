// 01 calloc和realloc.c : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include "pch.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>//offsetof()
void printArray(int *p,int len)
{
	int * temp = p;
	int temp_len = len;
	int i;
	for (i = 0; i < temp_len; ++i)
	{
		printf("%d\n",*(p + i));
	}
}
void test01(void)
{
	int *p = malloc((sizeof(int))*10);
	//int *p = calloc(10,sizeof(int));//calloc和malloc不同的地方在于 将堆区分配的内容初始化为0
	int i;
	if (p)
	{
		for (i = 0; i < 10; i++)
		{
			*p++ = i;
		}
	}
	printArray(p=p-10,10);
	if (p)
	{
		free(p);
		p = NULL;
	}
}
//malloc重新在堆区分配内存
int test02(void) 
{
	int *p = malloc(sizeof(int)*10);
	if (!p) 
	{
		return NULL;
	}
	int i;
	for (i = 0; i < 10; ++i) 
	{
		*(p + i)= i;
	}
	printf("%d\n",p);
	printArray(p, 10);
	p = realloc(p, sizeof(int) * 11);
	printf("%d\n", p);
	p = realloc(p,sizeof(int)*20);
	printf("%d\n", p);
	printArray(p, 20);
	if (p)
	{
		free(p);
		p = NULL;
	}
	return 0;
}
int main()
{
	//test01();
	test02();
	return 0;
}
