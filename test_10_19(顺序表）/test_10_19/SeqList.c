#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"
void SeqListInit(SeqList* ps1)//˳���ĳ�ʼ��
{
	ps1->array =(int*)malloc(3*sizeof(int));
	if (ps1->array == NULL)
	{
		printf("SeqListInit:%s", strerror(errno));

	}
	ps1->size = 0;
	ps1->capacity = 3;
}
void SeqListDestory(SeqList* ps1)//˳��������
{
	free(ps1->array);
	ps1->array = NULL;
	ps1->size = 0;
	ps1->capacity = 0;

}
void SeqListPrint(SeqList* ps1)//˳���Ĵ�ӡ
{
	int i;
	for (i = 0; i < ps1->size; i++)
	{
		printf("%d ", ps1->array[i]);
	}
	printf("\n");
}
void CheckCapacity(SeqList* ps1)//���ռ�
{
	if (ps1->size == ps1->capacity)
	{
		ps1->array = (int*)realloc(ps1->array,(ps1->capacity + 2)*sizeof(int)); 
		ps1->capacity += 2;
		/*printf("���ٳɹ�\n");*/
	}
	if (ps1->array == NULL)
	{
		printf("CheckCapacity:%s", strerror(errno));
	}
	
}
void SeqListPushBack(SeqList* ps1, SLDataType x)//˳���β��
{
	CheckCapacity(ps1);
	ps1->array[(ps1->capacity)-(ps1->size)-1] = x;
	ps1->size++;
}
void SeqListPopBack(SeqList* ps1)//˳���βɾ
{
	assert(ps1 && ps1->size != 0);
	ps1->size--;
}
void SeqListPushFront(SeqList* ps1, SLDataType x)//˳���ͷ��
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
void SeqListPopFront(SeqList* ps1)//˳���ͷɾ
{
	assert(ps1 && ps1->size != 0);
	int i = 0;
	for (i = 0; i < ps1->size -1; i++)
	{
		ps1->array[i] = ps1->array[i+1];
	}
	ps1->size--;
}
void SeqListFind(SeqList* ps1, SLDataType x)//˳������
{
	int i = 0;
	for(i = 0; i < ps1->size;i++)
	{
		if (ps1->array[i] == x)
		{
			printf("�±��ǣ�%d\n", i);
			return;
		}
		
	}
		printf("�����ҵ����ݲ�����\n");
	
}
void SeqListInsert(SeqList* ps1, int pos, SLDataType x)//˳�����posλ�ò���x
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
void SepListErase(SeqList* ps1, int pos)//��˳����posλ��ɾ��
{
	assert(ps1 && ps1->size != 0);
	int i = 0;
	for (i = 0; i < ps1->size - pos; i++)
	{
		ps1->array[i+pos] = ps1->array[i+ pos + 1];
	}
	ps1->size--;

}