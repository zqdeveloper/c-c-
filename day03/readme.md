1. calloc和realloc
	
	1.1 calloc和malloc一样都是在堆区分配内存
	
	1.2 不同点在于calloc会将分配的内存初始化为0
	
	1.3 relloc重新在堆区分配内存
			
		1.3.1 如果分配的内存比原来要大，这个时候有两种情况出现
		
		1.3.2 原有空间后序有足够大的空闲空间，那么直接在原有空间后继续开辟内存，返回原有空间的首地址
		
		1.3.3 原有空间后序没有足够大空闲空间吗，重新回分配一个足够大的空间，并且将原有空间的内容拷贝到新空间下，释放原有空间，将新空间的首地址返回
		
2. sscanf的使用
			
	2.1 将已经字符串通过格式化匹配出有效信息
	
		|---------------|---------------------------------------|
		|    格式      	|	        作用                        |
		|---------------|---------------------------------------|
		|  %*s或者%*d	| 	跳过数据					        |
		|---------------|---------------------------------------|
		|  %[width]s	|   读取指定宽度的数据					|	
		|---------------|---------------------------------------|
		|  %[a-z] 		|	匹配a到z中任意字符（尽可能多的匹配）|
		|---------------|---------------------------------------|
		|  %[aBc]       |   匹配a、B、C中一员，贪婪性			|
		|---------------|---------------------------------------|
		|  %[^a]        |   匹配非a得任意字符，贪婪性           |
		|---------------|---------------------------------------|
		|  %[^a-z]		|   表示读取除a-z以外的所有字符         |
		|---------------|---------------------------------------|
	
	2.2 案列
		
		2.2.1 匹配char *p="127.0.0.1"将中间数字匹配到num1~num4中
		
		2.2.2 字符串char *str="abcde#zhangtao@12345"中间的zhangtao匹配出来;
		
3. 查找子串

	3.1 实现自己的查找子串功能，需求在字符串中查找对应的子串，如果有返回字符串第一个字母的位置，如果没有返回-1
	
4. 指针的易错点

	4.1 指针易容越界操作
	
	4.2 指针叠加会不断改变指针指向
	
	4.3 返回局部变量地址
	
	4.4 不可以释放野指针
	
5. const 的使用场景
	
	5.1 用来修饰函数中的形参，防止误操作
	
6.二级指针做函数参数的输入输出特性
	
	6.1 输入特性
	
		6.1.1 在主调函数分配内存，被调函数使用
		
		6.1.2 在堆区创建
		
		6.1.3 在栈上创建
	
	6.2 输出特性
		
		6.2.1 在被调函数中分配内存，主调函数使用
		
7. 二级指针练习文件读写
	
	7.1 需求：从文件中读取数据，并且将数据存放到堆区的数组中
	
		7.1.1 char **pArray=malloc(sizeof(char*)*len)
	
	7.2 获取有效行数
	
		7.2.1 将文件光标置为文件首fseek(file,0,SEEK_SET)
		
	7.3 读取文件数据并且放入到pArray中
	
	7.4 显示数组pArray
	
	7.5 释放数组pArray
	
	
