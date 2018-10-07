#pragma once
#include "pch.h"
#define  _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "GameCompany.h"
struct Player
{
	char name[64];//玩家姓名
	int level;//代表了玩家的等级
	int exp;//玩家经验
};
//初始化游戏
void INIT_GAME_COMPANY(void **gameHandle, char * name)
{
	struct Player *player=malloc(sizeof(struct Player));
	if (!player)
	{
		return;
	}
	strcpy(player->name,name);
	player->level = 0;
	player->exp = 0;
	*gameHandle = player;
}

//游戏战斗,返回游戏战斗的结果，如果是1 代表游戏胜利 返回0代表游戏失败
int FIGHT_GAME_COMPANY(struct Player *gameHandle, int gameLevel)
{
	int addExp = 0;//累加的经验值
	switch (gameLevel)
	{
	case 1:
		addExp = isWin(90, 1);
		break;
	case 2:
		addExp = isWin(50, 2);
		break;
	case 3:
		addExp = isWin(30, 3);
		break;
	default:
		break;
	}
	gameHandle->exp += addExp;
	gameHandle->level = gameHandle->exp / 10;
	if (addExp==0)
	{
		return 0;
	}
	return 1;
}

//查看玩家信息
void PRINT_GAME_COMPANY(struct Player  *gameHandle)
{
	printf("姓名:%s 等级:%d  经验:%d\n", gameHandle->name, gameHandle->level, gameHandle->exp);
}

//离开游戏
void CLOSE_GAME_COMPANY(void *gameHandle)
{
	if (!gameHandle)
	{
		return;
	}
	if (gameHandle)
	{
		free(gameHandle);
		gameHandle = NULL;
	}
}

//判断游戏是否胜利,参数1 胜率 参数2 难度 返回值 胜利后的经验，如果返回的是0，代表战斗失败
int isWin(int winRate, int diff)
{
	int random = rand()%100+1;//1~100
	if (random<=winRate)//代表胜利
	{
		return 10 * diff;
	}
	return 0;
}