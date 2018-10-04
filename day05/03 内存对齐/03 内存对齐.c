// 03 内存对齐.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include "pch.h"
#define  _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#pragma  pack(show)//查看对齐模数
//#pragma  pack(1)//默认对齐模数为8 对齐模数可以改为2的n次方
//对于自定义数据类型  内存对齐规则如下：
//1、从第一个属性开始 偏移为0
//2、第二个属性开始，地址要放在  该类型的整数倍   与对齐模数比         取小的值的整数倍上
//3、所有的属性都计算结束后，整体再做二次对齐，整体需要放在最大类型与对齐模数比取小的值的整数倍上
typedef struct _STUDENT
{
	int a;//0-3
	char b;//4-7
	double c;//8-15
	float d;//16-19
}Student;
void test01(void)
{
	printf("sizeof double=%d\n", sizeof(double));
	printf("sizeof float=%d\n", sizeof(float));
	printf("sizeof struct Student=%d\n",sizeof(Student));
}
typedef struct _STUDENT2
{
	char a;//0-7
	Student b;//8-31
	double c;//32-39
}Student2;
//当结构体嵌套结构体时只需要看结构体中最大数据类型就可以了
void test02(void)
{
	printf("sizeof _Student2=%d\n", sizeof(Student2));
}
int main()
{
	//test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}