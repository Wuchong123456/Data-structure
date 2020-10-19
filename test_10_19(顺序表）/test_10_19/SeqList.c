#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"
void SeqListInit(SeqList* ps1)//顺序表的初始化
{
	ps1->array =(int*)malloc(3*sizeof(int));
	if (ps1->array == NULL)
	{
		printf("SeqListInit:%s", strerror(errno));

	}
	ps1->size = 0;
	ps1->capacity = 3;
}
void SeqListDestory(SeqList* ps1)//顺序表的销毁
{
	free(ps1->array);
	ps1->array = NULL;
	ps1->size = 0;
	ps1->capacity = 0;

}
void SeqListPrint(SeqList* ps1)//顺序表的打印
{
	int i;
	for (i = 0; i < ps1->size; i++)
	{
		printf("%d ", ps1->array[i]);
	}
	printf("\n");
}
void CheckCapacity(SeqList* ps1)//检查空间
{
	if (ps1->size == ps1->capacity)
	{
		ps1->array = (int*)realloc(ps1->array,(ps1->capacity + 2)*sizeof(int)); 
		ps1->capacity += 2;
		/*printf("开辟成功\n");*/
	}
	if (ps1->array == NULL)
	{
		printf("CheckCapacity:%s", strerror(errno));
	}
	
}
void SeqListPushBack(SeqList* ps1, SLDataType x)//顺序表尾插
{
	CheckCapacity(ps1);
	ps1->array[(ps1->capacity)-(ps1->size)-1] = x;
	ps1->size++;
}
void SeqListPopBack(SeqList* ps1)//顺序表尾删
{
	assert(ps1 && ps1->size != 0);
	ps1->size--;
}
void SeqListPushFront(SeqList* ps1, SLDataType x)//顺序表头插
{
	CheckCapacity(ps1);
	int i = 0;
	for (i = 0; i < ps1->size; i++)
	{
		ps1->array[ps1->size - i] = ps1->array[ps1->size -i- 1];
	}
	ps1->array[0] = x;
	ps1->size++;
}
void SeqListPopFront(SeqList* ps1)//顺序表头删
{
	assert(ps1 && ps1->size != 0);
	int i = 0;
	for (i = 0; i < ps1->size -1; i++)
	{
		ps1->array[i] = ps1->array[i+1];
	}
	ps1->size--;
}
void SeqListFind(SeqList* ps1, SLDataType x)//顺序表查找
{
	int i = 0;
	for(i = 0; i < ps1->size;i++)
	{
		if (ps1->array[i] == x)
		{
			printf("下标是：%d\n", i);
			return;
		}
		
	}
		printf("所查找的数据不存在\n");
	
}
void SeqListInsert(SeqList* ps1, int pos, SLDataType x)//顺序表在pos位置插入x
{
	CheckCapacity(ps1);
	int i = 0;
	for (i = 0; i < (ps1->size - (pos-1)); i++)
	{
		ps1->array[ps1->size - i] = ps1->array[ps1->size - i - 1];
	}
	ps1->array[pos] = x;
	ps1->size++;
}
void SepListErase(SeqList* ps1, int pos)//在顺序表的pos位置删除
{
	assert(ps1 && ps1->size != 0);
	int i = 0;
	for (i = 0; i < ps1->size - pos; i++)
	{
		ps1->array[i+pos] = ps1->array[i+ pos + 1];
	}
	ps1->size--;

}