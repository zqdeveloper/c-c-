#pragma once
#include "pch.h"
#define  _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

//动态数组的结构体
struct dynamicArray
{
	void **pAddr;//维护在堆区真实数组指针
	int m_capacity;//数组的容量
	int m_size;//数组大小
};
//初始化数组
struct dynamicArray * init_DynamicArray(int capacity);

//插入功能
void insert_dynamicArray(struct dynamicArray*array, int pos, void *data);

//遍历功能
void foreach_DynamicArray(struct dynamicArray *array, void(*mForeach)(void *));

//删除功能--按照指定位置进行删除
void remove_dynamicArray(struct dynamicArray * array, int pos);

//删除数组中元素，按照元素来删除
void removeByValue(struct dynamicArray *array, void * data, int(*compare)(void *, void *));

//销毁数组
void destroy(struct dynamicArray *array);