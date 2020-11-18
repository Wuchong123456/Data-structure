#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* _a;
	int _size;
	int _capacity;
}Heap;

void HeapCreate(Heap* hp, HPDataType* a, int n);// 堆的构建
void HeapDestory(Heap* hp);// 堆的销毁
void HeapPush(Heap* hp, HPDataType x);// 堆的插入
void HeapPop(Heap* hp);// 堆的删除
// 取堆顶的数据
HPDataType HeapTop(Heap* hp);
// 堆的数据个数
int HeapSize(Heap* hp);
// 堆的判空
int HeapEmpty(Heap* hp);
// 对数组进行堆排序
void HeapSort(int* a, int n);
//打印数据
void HeapPrint(Heap* hp);
