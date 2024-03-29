// 01 回调函数案例-实现对任意数组进行排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include "pch.h"
#define  _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
void selectSort(void * pArray, int len, int eleSize, int(*Compare)(void *, void *))
{
	char *  pc = malloc(eleSize);
	int i, j;
	char *p = pArray;
	for (i = 0; i < len; i++)
	{
		int temp = i;
		for (j = i + 1; j < len; j++)
		{
			void *pI = p + temp * eleSize;
			void *pJ= p + j * eleSize;
			if (Compare(pJ,pI))
			{
				temp = j;
			}
		}
		if (temp!=i)
		{
			//交换数据
			char *ptemp=p+temp*eleSize;
			char *pI = p + i * eleSize;
			memcpy(pc, ptemp, eleSize);
			memcpy(ptemp, pI, eleSize);
			memcpy(pI, pc, eleSize);
		}
	}
	if (pc)
	{
		free(pc);
		pc = NULL;
	}
}
int myComplareInt(int *p1, int *p2)
{
	return *p1 >*p2;
}
void test01()
{
	int arr[8] = {1,8,2,7,3,6,4,5};
	int len=sizeof(arr)/sizeof(int);
	selectSort(arr, len, sizeof(int), myComplareInt);
	int i;
	for (i = 0; i < len; i++)
	{
		printf("%d\n", *(arr + i));
	}
}
struct Person
{
	char name[64];
	int age;
};
int ComplarePerson(struct Person *p1, struct Person *p2)
{
	return p1->age > p2->age;
}
void printPerson(struct Person *p, int len)
{
	int i;
	for (i=0;i<len;i++)
	{
		printf("姓名:%s  年龄:%d\n", (p + i)->name, (p + i)->age);
	}
}
void test02()
{
	struct Person persons[] = 
	{
		{"aaa",10},
		{"bbb",20},
		{"ccc",30},
		{"ddd",40},
		{"eee",50}
	};
	printf("排序之前:\n");
	int len = sizeof(persons) / sizeof(struct Person);
	printPerson(persons, len);
	selectSort(persons, len, sizeof(struct Person), ComplarePerson);
	printf("排序之后:\n");
	printPerson(persons, len);
}
int main()
{
	//test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}