#include "pch.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
//栈，注意事项，不要返回局部变量的地址，我们没有权限操作这块内存
int * func() {
	int a = 10;
	return &a;
}
char * getString(void) {
	char str[] = "hello world";
	return str;
}
void test01() {
	int *result = func();
	//结果已经不重要了，因为a的内存已经被释放了，我们没有权限去操作这块内存
	printf("%d\n", *result);
	printf("%d\n", *result);
}
void test02() {
	char * p = getString();
	printf("%s",p);
}
int main()
{
	test01();
	test02();
	return 0;
}
