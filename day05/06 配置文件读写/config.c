#include "pch.h"
#include "config.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//获取有效行数
int getFileLine(char * filename)
{
	FILE *f_read = fopen(filename, "r");
	if (!f_read)
	{
		return -1;
	}
	char buf[1024] = { 0 };
	int lines = 0;
	while (fgets(buf, 1024, f_read))
	{
		//如果是有效的一个行，才去统计
		if (isValidLine(buf))
		{
			lines++;
		}
	}
	fclose(f_read);
	return lines;
}


//判断当前行是否有效
int isValidLine(char * str)
{
	if (str[0] == ' ' || str[0] == '\0' || !strchr(str, ':'))
	{
		return 0;//无效数据 都返回假，有效数据返回真
	}
	return 1;
}

//解析文件
void parserFile(char * filePath, int lines, struct ConfigInfo **configInfo)
{
	struct ConfigInfo  *info = malloc(sizeof(struct ConfigInfo)*lines);
	if (!info)
	{
		return;
	}
	FILE * f_read = fopen(filePath, "r");
	if (!f_read)
	{
		return;
	}
	int index = 0;
	char buf[1024] = { 0 };
	while (fgets(buf, 1024, f_read))
	{
		if (isValidLine(buf))
		{
			memset((info + index)->key, 0, 64);
			memset((info + index)->value, 0, 64);
#if 0
			sscanf(buf, "%[^:]:%s", (info + index)->key, (info + index)->value);
#else
			char *pos = strchr(buf, ':');
			strncpy((info + index)->key,buf,pos-buf);//将key截取到结构体中
			strncpy((info + index)->value, pos+1,strlen(pos+1)-1);//最后减1的原因是不需要截取换行符
#endif
			index++;
		}
		memset(buf, 0,1024);
	}
	fclose(f_read);
	*configInfo = info;
}

//根据索引值获取实值 
char * getInfoByKey(char * key, struct ConfigInfo *configInfo, int line)
{
	int i;
	for (i=0;i<line;i++)
	{
		if (!strcmp((configInfo + i)->key,key))
		{
			return (configInfo + i)->value;
		}
	}
	return NULL;
}
//释放信息
void freeSpace(struct ConfigInfo * configInfo)
{
	if (configInfo)
	{
		free(configInfo);
		configInfo = NULL;
	}
}