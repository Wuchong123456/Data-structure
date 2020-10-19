
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
void SeqListInit(SeqList* ps1);//˳���ĳ�ʼ��
void SeqListDestory(SeqList* ps1);//˳��������
void SeqListPrint(SeqList* ps1);//˳���Ĵ�ӡ
void CheckCapacity(SeqList* ps1);//���ռ�
void SeqListPushBack(SeqList* ps1,SLDataType x);//˳���β��
void SeqListPopBack(SeqList* ps1);//˳���βɾ
void SeqListPushFront(SeqList* ps1, SLDataType x);//˳���ͷ��
void SeqListPopFront(SeqList* ps1);//˳���ͷɾ
void SeqListFind(SeqList* ps1, SLDataType x);//˳������
void SeqListInsert(SeqList* ps1, int pos, SLDataType x);//˳�����posλ�ò���x
void SepListErase(SeqList* ps1, int pos);//��˳����posλ��ɾ��