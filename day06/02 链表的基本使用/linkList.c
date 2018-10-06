#include "pch.h"
#include "linkList.h"
#include "pch.h"
#define  _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

//初始化链表
struct LinkNode * init_linkList()
{
	struct LinkNode * p = malloc(sizeof(struct LinkNode));
	if (!p)
	{
		return NULL;
	}
	p->num = -1;//头节点不维护数据域
	p->next = NULL;//头节点初始化指针域为NULL
	int value = -1;

	//创建一个尾节点，利于后期添加新的数据
	struct LinkNode *pTail = p;
	while (1)
	{
		printf("请插入数据:(-1代表输入结束:)\n");
		scanf("%d", &value);
		if (value == -1)
		{
			break;
		}
		//创建新节点
		struct LinkNode * newNode = malloc(sizeof(struct LinkNode));
		newNode->num = value;
		newNode->next = NULL;

		//建立关系
		pTail->next = newNode;
		//更新下新的尾节点
		pTail = newNode;



	}
	return p;
}


//遍历链表
void foreach_linkList(struct LinkNode *pHeader)
{
	if (!pHeader)
	{
		return;
	}
	//pCurrent 起始指向的是第一个真实有效的节点
	struct LinkNode *pCurrent = pHeader->next;
	while (pCurrent)
	{
		printf("%d\n", pCurrent->num);
		pCurrent = pCurrent->next;
	}
}


//插入链表
void insert_linkList(struct LinkNode *pHeader, int oldVal, int newVal)
{
	if (!pHeader)
	{
		return;
	}
	//创建两个辅助指针变量
	struct LinkNode * pPrev = pHeader;
	struct LinkNode *pCurrent = pHeader->next;
	while (pCurrent)
	{
		if (pCurrent->num == oldVal)//找到插入位置
		{
			break;
		}
		//没有找到位置，让辅助指针后移
		pPrev = pCurrent;
		pCurrent = pCurrent->next;
	}

	//创建新节点
	struct LinkNode * newNode = malloc(sizeof(struct LinkNode));
	newNode->num = newVal;
	newNode->next = NULL;

	//建立关系,更新指针的指向
	newNode->next = pCurrent;
	pPrev->next = newNode;
}

//删除链表
void delete_linkList(struct LinkNode *pHeader, int val)
{
	if (!pHeader)
	{
		return;
	}
	struct LinkNode *pPrev = pHeader;
	struct LinkNode * pCurrent = pHeader->next;
	while (pCurrent)
	{
		if (pCurrent->num == val)
		{
			break;
		}
		pPrev = pCurrent;
		pCurrent = pCurrent->next;
	}
	if (!pCurrent)
	{
		return;
	}
	pPrev->next = pCurrent->next;
	free(pCurrent);
	pCurrent = NULL;
}

//清空链表
void clear_linkList(struct LinkNode *pHeader)
{
	if (!pHeader)
	{
		return;
	}
	//创建临时指针变量
	struct LinkNode * pCurrent = pHeader->next;
	while (pCurrent)
	{
		//先保存住待删除节点后面的节点
		struct LinkNode *nextNode = pCurrent->next;
		free(pCurrent);
		pCurrent = NULL;
		pCurrent = nextNode;
	}
	//头节点的next置空
	pHeader->next = NULL;

}

//销毁
void destroty_linkList(struct LinkNode *pHeader)
{
	if (!pHeader)
	{
		return;
	}
	//先清空链表
	clear_linkList(pHeader);
	//再释放头节点
	free(pHeader);
	pHeader = NULL;
}

