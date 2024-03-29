// 04 指针数组的排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#define  _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

//从小到大 选择排序
void printArray(int arr[], int len)
{
	int i;
	for (i=0;i<len;i++)
	{
		printf("%d\n", *(arr + i));
	}
}
void selectSore01(int arr[], int len)
{
	int i, j;
	for (i = 0; i < len; ++i)
	{
		int min = i;
		for (j = i + 1; j < len; ++j)
		{
			if (arr[min] > arr[j])
			{
				min = j;
			}
		}
		if (min != i)
		{
			arr[i] = arr[i] ^ arr[min];
			arr[min] = arr[i] ^ arr[min];
			arr[i] = arr[i] ^ arr[min];
		}
	}

}
void test01(void)
{
	int arr[] = { 3,2,5,1,4 };
	int len = sizeof(arr) / sizeof(arr[0]);
	printf("排序前:\n");
	printArray(arr,len);
	selectSore01(arr, len);
	printf("排序后:\n");
	printArray(arr, len);
}


//通过选择排序算法计算后，实现对指针数据的降序排列,从大到小
void selectSort02(char **pArr, int len)
{
	int i, j;
	for (i=0;i<len;i++)
	{
		int max = i;
		for (j=i+1;j<len;j++)
		{
			if (strcmp(pArr[max],pArr[j])<0)
			{
				max = j;
			}
		}
		if (max!=i)
		{
			char *temp=pArr[i];
			pArr[i] = pArr[max];
			pArr[max]=temp;
		}
	}
}
void printCharArray(char **p, int len)
{
	int i ;
	for (i=0;i<len;i++)
	{
		printf("%s\n", p[i]);
	}
}
void test02(void)
{
	char *pArr[] = { "aaa","bbb","fff","ddd","eee","ccc" };
	int len = sizeof(pArr) / sizeof(char*);
	printf("排序前:\n");
	printCharArray(pArr, len);
	selectSort02(pArr, len);
	printf("排序后:\n");
	printCharArray(pArr, len);
}


int main()
{
	//test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}