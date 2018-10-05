#pragma once
#include "pch.h"
#define  _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

//节点声明
struct LinkNode
{
	int num;
	struct LinkNode *next;
};
//初始化链表
struct LinkNode * init_linkList();
//遍历链表
void foreach_linkList(struct LinkNode *pHeader);
