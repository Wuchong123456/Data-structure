
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* array;
	int size;
	int capacity;
}SeqList;
void SeqListInit(SeqList* ps1);//顺序表的初始化
void SeqListDestory(SeqList* ps1);//顺序表的销毁
void SeqListPrint(SeqList* ps1);//顺序表的打印
void CheckCapacity(SeqList* ps1);//检查空间
void SeqListPushBack(SeqList* ps1,SLDataType x);//顺序表尾插
void SeqListPopBack(SeqList* ps1);//顺序表尾删
void SeqListPushFront(SeqList* ps1, SLDataType x);//顺序表头插
void SeqListPopFront(SeqList* ps1);//顺序表头删
void SeqListFind(SeqList* ps1, SLDataType x);//顺序表查找
void SeqListInsert(SeqList* ps1, int pos, SLDataType x);//顺序表在pos位置插入x
void SepListErase(SeqList* ps1, int pos);//在顺序表的pos位置删除