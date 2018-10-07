#pragma once
#include "pch.h"
#define  _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
//初始化游戏
 void INIT_GAME_COMPANY(void **gameHandle, char * name);

//游戏战斗,返回游戏战斗的结果，如果是1 代表游戏胜利 返回0代表游戏失败
 int FIGHT_GAME_COMPANY(struct Player  *gameHandle, int gameLevel);

//查看玩家信息
void PRINT_GAME_COMPANY(struct Player  *gameHandle);

//离开游戏
 void CLOSE_GAME_COMPANY(struct Player  *gameHandle);

 //判断游戏是否胜利,参数1 胜率 参数2 难度 返回值 胜利后的经验，如果返回的是0，代表战斗失败
 int isWin(int winRate, int diff);
