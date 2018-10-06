1.链表的基本概念

    1.1 链表的引出

        1.1.1 数组有缺陷

        1.1.2 静态空间，一旦分配内存就不可以动态扩展，要不分配不够，要不分配过多

        1.1.3 对于数组头部进行插入和删除效率低
    
    1.2 链表的组成

        1.2.1 链表是由节点组成的

        1.2.2 节点由 数据域 和 指针域组成

        1.2.3 struct LinkNode{int num;struct LinkNode *next;};

    1.3 链表的分类

        1.3.1 方式1 静态链表 动态链表

        1.3.2 方式2 单向链表 双向链表 单向循环链表 双向循环链表

2.静态链表和动态链表

    2.1 静态链表 创建在栈上

    2.2 动态链表 创建在堆区

3.链表的基本使用

    3.1 带头节点链表 好处在于 头节点永远都是固定的

    3.2 初始化链表 struct LinkNode * init_linkList()

    3.3 遍历链表 void foreach_linkList(struct LinkNode *pHeader)

    3.4 插入链表 void insert_linkList(struct LinkNode *pHeader,int oldVal,int newVal);

        3.4.1 在oldVa前插入newVal,如果没有oldVal就进行尾插
    
    3.5 删除链表 void delete_linkList(struct LinkNode *pHeader,int val);

        3.5.1 用户提供的有效数据 删除掉

        3.5.2 无效数据，直接return
    
    3.6 清空链表

        3.6.1 void clear_linkList(struct LinkNode *pHeader) 将所有有数据的节点释放掉

    3.7 销毁链表

        3.7.1 void destroty_linkList(struct LinkNode *pHeader)

        3.7.2 将整个链表都释放掉

4.函数指针的定义

    4.1 先定义出函数指针的类型，再定义函数指针 
        
        4.1.1 typedef void(FUNC_TYPE)(void);

        4.1.2 FUNC_TYPE *Pfunc = func;

    4.2 先定义出函数类型，再通过类型定义出函数指针 
    
        4.2.1 typedef void (*FUNC_TYPE)(void);

        4.2.2 FUNC_TYPE Pfunc = func;

    4.3 直接定义函数指针变量

        4.3.1 void(*pFunc)(void) = func;
    
    4.4 函数指针和指针函数的区别

        4.4.1 函数指针 是指向函数的指针

        4.4.2 指针函数 函数的返回值是一个指针的函数
    
    4.5 函数指针的数组定义

        4.5.1 void(*pFunc[3])();

5.函数指针做函数参数(回调函数)

    5.1 提供一个通用的函数，可以打印任意的数据类型

6.回调函数

    6.1 提供一个函数，打印任意类型的数组

    6.2 提供一个查找数组中元素的函数

7.作业

    7.1 提供一个函数，可以对任意类型的数组进行排序，排序规则 选择排序