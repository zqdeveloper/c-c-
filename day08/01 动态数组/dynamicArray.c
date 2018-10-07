#include "pch.h"
#include "dynamicArray.h"

//初始化数组
struct dynamicArray * init_DynamicArray(int capacity)
{
	if (capacity <= 0)
	{
		return NULL;
	}
	struct dynamicArray *array = malloc(sizeof(struct dynamicArray));
	if (!array)
	{
		return NULL;
	}
	array->m_capacity = capacity;
	array->m_size = 0;
	array->pAddr = malloc(sizeof(void*)*array->m_capacity);
	return array;
}

//插入功能
void insert_dynamicArray(struct dynamicArray*array, int pos, void *data)
{
	if (!array)
	{
		return;
	}
	if (!data)
	{
		return;
	}
	if (pos<0 || pos>array->m_size)
	{
		//无效的位置，进行尾插
		pos = array->m_size;
	}
	//先判断是否满载，如果满了，动态进行开辟
	if (array->m_size >= array->m_capacity)
	{
		//1、申请一个更大的内存空间
		int newCapacity = array->m_capacity * 2;
		//2、创建新空间
		void **newSpacec = malloc(sizeof(void*)*newCapacity);
		//3、将原有的数据，拷贝到新空间下
		memcpy(newSpacec, array->pAddr, sizeof(void*)*array->m_capacity);
		//4、释放原有空间
		free(array->pAddr);
		//6、更新新容量大小
		array->pAddr = newSpacec;
		array->m_capacity = newCapacity;
	}
	//插入新数据元素
	//从最后一个位置开始依次移动数据 后移
	int i;
	for (i = array->m_size - 1; i >= pos; i--)
	{
		array->pAddr[i + 1] = array->pAddr[i];
	}
	//将新元素插入到指定位置
	array->pAddr[pos] = data;
	//更新大小
	array->m_size++;
}

//遍历功能
void foreach_DynamicArray(struct dynamicArray *array, void(*mForeach)(void *))
{
	if (!array)
	{
		return;
	}
	if (!mForeach)
	{
		return;
	}
	int i;
	for (i = 0; i < array->m_size; i++)
	{
		mForeach(array->pAddr[i]);
	}
}

//删除功能--按照指定位置进行删除
void remove_dynamicArray(struct dynamicArray * array, int pos)
{
	if (!array)
	{
		return;
	}
	if (pos<0 || pos>array->m_size - 1)
	{
		return;
	}
	int i;
	for (i = pos; i < array->m_size - 1; i++)
	{
		array->pAddr[i] = array->pAddr[i + 1];
	}
	array->m_size--;
}

//删除数组中元素，按照元素来删除
void removeByValue(struct dynamicArray *array, void * data, int(*compare)(void *, void *))
{
	if (!array)
	{
		return;
	}
	if (!data)
	{
		return;
	}
	if (!compare)
	{
		return;
	}
	int i;
	for (i = 0; i < array->m_size; i++)
	{
		if (compare(array->pAddr[i], data))
		{
			remove_dynamicArray(array, i);
			break;
		}
	}
}

//销毁数组
void destroy(struct dynamicArray *array)
{
	if (!array)
	{
		return;
	}
	if (array->pAddr)
	{
		free(array->pAddr);
		array->pAddr = NULL;
	}
	if (array)
	{
		free(array);
		array = NULL;
	}
}

