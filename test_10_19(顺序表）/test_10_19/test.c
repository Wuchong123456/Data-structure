#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

void TestSeqList()
{
	SeqList s;
	SeqListInit(&s);
	
	CheckCapacity(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 1);
	SeqListPopBack(&s);
	SeqListPushFront(&s, 2);
	SeqListPushFront(&s, 2);
	SeqListPushFront(&s, 2);
	SeqListPopFront(&s);
	SeqListInsert(&s, 2, 10);
	SepListErase(&s, 3);
	SeqListPrint(&s);
	SeqListFind(&s,10);
	SeqListDestory(&s);

}
int main()
{
	TestSeqList();
	return 0;
}
