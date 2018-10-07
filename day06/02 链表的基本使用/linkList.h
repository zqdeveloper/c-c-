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

//插入链表
void insert_linkList(struct LinkNode *pHeader,int oldVal,int newVal);

//删除链表
void delete_linkList(struct LinkNode *pHeader,int val);

//清空链表
void clear_linkList(struct LinkNode *pHeader);

//销毁
void destroty_linkList(struct LinkNode *pHeader);

//反转链表
void reverse_linkList(struct LinkNode *pHeder);

//返回链表的长度
int size_linkList(struct LinkNode*pHeader);

//利用递归 逆序遍历
void printLinkList(struct LinkNode*pHeader);

//利用递归 逆序遍历
void printLinkList(struct LinkNode*pHeader);
