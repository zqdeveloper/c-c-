#include "pch.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>//offsetof的头文件
//指针步长的意义
//1.指针变量+1之后 跳跃的字节数量
void test01()
{
	char * p = NULL;
	printf("%d\n", p);
	printf("%d\n", p + 1);

	double *p2 = NULL;
	printf("%d\n", p2);
	printf("%d\n", p2 + 1);
}
//2、解引用的时候，取的字节数
typedef struct Person 
{
	char a;
	int b;
	char buf[64];
	int d;

}P;
void test02(void)
{
	P p1 = {'a',10,"hello world",1000};
	//计算结构体中属性的偏移量
	printf("p1.d的偏移量为:%d\n", offsetof(P,d));
	//打印d的值
	printf("d=%d\n",*(int*)((char*)&p1 + offsetof(P, d)));
}
int main()
{
	//test01();
	test02();
	return 0;
}
