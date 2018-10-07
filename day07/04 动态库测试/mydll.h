#pragma once
#include <stdio.h>

//导出函数 能在项目外使用
__declspec(dllexport) int mySub(int a, int b);