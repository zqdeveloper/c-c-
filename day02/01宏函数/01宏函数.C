#include "pch.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1024
#define add(x,y) ((x)+(y))
//1.宏函数 要保证运算的完整性
//2.宏函数 在一定程度上会比普通函数效率高,普通函数会有入栈和出栈的时间开销
//我们通常将一些比较频繁、短小的函数封装为宏函数
void test01()
{
	int a, b;
	a = 10;
	b = 20;
	int result = add(a, b) * 20;
	printf("%d\n", result);
}
int myadd(int x, int y) {
	return x + y;
}
int main()
{
	test01();
	return 0;
}