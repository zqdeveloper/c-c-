// 05 文件读写注意事项.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include "pch.h"
#define  _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

void test01(void)
{
	FILE *f_read = fopen("test01.txt", "r");
	if (!f_read)
	{
		return;
	}
	char ch;
#if 0
	while (!feof(f_read))
	{
		ch = fgetc(f_read);
		//滞后性
		if (feof(f_read))
		{
			break;
		}
		printf("%c", ch);
	}
	rewind(f_read);
#endif
	while ((ch = fgetc(f_read))!=EOF)
	{
		printf("%c", ch);
	}
	fclose(f_read);
}
//注意事项2
struct Person
{
	char *name;//不要将指针写入到文件中 
	int age;
};

int main()
{
	test01();
	char * name=calloc(1024,sizeof(char));
	strcpy(name, "hello world");
	printf("\n%s\n", name);
	if (name)
	{
		free(name);
		name = NULL;
	}
	system("pause");
	return EXIT_SUCCESS;
}