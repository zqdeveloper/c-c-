1.数据结构的基本概念

    1.1.算法

        1.1.1 5个特性：输入 输出 有穷 确定（不能过出现二义性） 可行性

    1.2 数据结构的分类

        1.2.1 逻辑结构

            1.2.1.1 集合 元素之间没有关系，都是平等的，不去探讨

            1.2.1.2 线性 1:1关系 除了第一个元素没有前驱，最后一个元素没有后继，其它元素都有唯一的前驱和唯一的后继

            1.2.1.3 树形 1:n

            1.2.1.4 图形 n:n
        
        1.2.2 物理结构

            1.2.2.1 顺序存储

            1.2.2.2 链式存储

2.动态数组

    2.1 初始化
    
    2.2 插入数据

        2.2.1 判断是否已经满载，如果满载，动态开辟内存

        2.2.2 插入数据

    2.3 遍历数据

            2.3.1 将数组中的每个元素进行遍历，利用回调函数
        
    2.4 删除数据

        2.4.1 按照位置进行删除

        2.4.2 按照值进行删除
    
    2.5 销毁数组