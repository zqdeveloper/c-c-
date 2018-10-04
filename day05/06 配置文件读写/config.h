#pragma once
#include "pch.h"
#define  _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
struct ConfigInfo
{
	char key[64];//索引值
	char value[64];//实值
};
//获取有效行数
int getFileLine(char * filename);

//判断当前行是否有效
int isValidLine(char * str);

//解析文件
void parserFile(char * filePath, int lines, struct ConfigInfo **configInfo);
//根据索引值获取实值 
char * getInfoByKey(char * key, struct ConfigInfo *configInfo, int line);
//释放信息
void freeSpace(struct ConfigInfo * configInfo);