#include "pch.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int g_a = 10;//全局区的数据在main和func1、func2中都可以使用
//子函数1
void func1(void)
{
	int a = 10;//在main函数中 不可以使用，在func1、func2中都可以使用
	func2();
}
//子函数2
void func2(void)
{

}
int main()
{
	int a = 10;//在main和func1、func2中都可以使用
	func1();
	return 0;
}
