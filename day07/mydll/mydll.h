#pragma once
#include <stdio.h>

//导出函数 能在项目外使用
__declspec(dllexport) int mySub(int a, int b);

// 动态库生成的.lib 和静态库生成的.lib文件不同
//动态库中的.lib只会存放一些导出函数的声明和一些变量的声明，而具体的实现在.dll文件中