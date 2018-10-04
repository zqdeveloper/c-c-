// 02 结构体偏移量.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include "pch.h"
#define  _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<stddef.h>
struct Person
{
	char a;//0~3
	int b;//4~7
};
void testo1(void)
{
	struct Person p1;
	struct Person *p = &p1;
	printf("b的偏移量为:%d\n", (int)&(p->b) - (int)p);
	printf("b的偏移量为:%d\n", offsetof(struct Person,b));
}
//通过偏移量获取书籍
void test02()
{
	struct Person p1 = {'a',10};
	printf("p.b=%d\n", p1.b);

	printf("p.b=%d\n", *(int*)((char*)(&p1) + offsetof(struct Person, b)));
	printf("p.b=%d\n", *(int*)((int*)(&p1) +1));

}
//结构体嵌套结构体
struct Person2
{
	char a;
	int b;
	struct Person c;
};
void test03(void)
{
	struct Person2 p = {'a',10,'b',20};
	printf("%d\n", p.c.b);
	int offset1 = offsetof(struct Person2, c);
	int offset2 = offsetof(struct Person, b);
	printf("%d\n", *(int*)((char*)&p + offset1 + offset2));
	printf("%d\n", ((struct Person*)((char*)&p + offset1))->b);
}
int main()
{
	//testo1();
	//test02();
	test03();
	system("pause");
	return EXIT_SUCCESS;
}