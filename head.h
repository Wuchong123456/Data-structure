#include "Heap.h"

void AdjustDown(int* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (1)
	{
		int i = 0;
		if (child + 1 > n)
		{
			break;
		}
		if (child + 1 < n && a[child + 1] < a[child])
		{
			child = child + 1;
		}
		if (a[child] < a[parent])
		{
			i = a[child];
			a[child] = a[parent];
			a[parent] = i;
		}
		else
		{
			break;
		}
		parent = child;
		child = child *2+ 1;

	}
}
void HeapPrint(Heap* hp)
{
	for (int i = 0; i < hp->_size; i++)
	{
		printf("%d ", hp->_a[i]);
	}
	printf("\n");
}
void Adjustup(int* a, int root)
{
	int parent = (root - 1) / 2;
	int child = root;
	while (child>0)
	{
		int i = 0;
		if (a[child] < a[parent])
		{
			i = a[child];
			a[child] = a[parent];
			a[parent] = i;
		}
		else
		{
			break;
		}
		child = parent;
		parent = (parent-1)/2;
	}
}
void HeapCreate(Heap* hp, HPDataType* a, int n)// 堆的构建
{
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType)*n);
	memcpy(hp->_a, a, sizeof(HPDataType)*n);
	hp->_size = n;
	hp->_capacity = n;
	int root = (n-2)/2;
   	for (; root >= 0; --root)
	{
		AdjustDown(hp->_a,hp->_size, root);
	}
}
void HeapSort(int* a, int n)//排序
{
	int i = (n - 2) / 2;
	for (; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}
	for (i = 0; i < n; i++)
	{
		printf("%d", a[i]);
	}
	printf("\n");
	int end = n - 1;
	while (end < 0)
	{
		int tmp = a[end];
		a[end] = a[0];
		a[0] = tmp;
		for (i = 0; i < n; ++i)
		{
			printf("%d ", a[i]);
		}
		AdjustDown(a, end, 0);
		--end;
	}
	for (i = 0; i < n; ++i)
	{
		printf("%d", a[i]);
	}
	printf("\n");
}
void HeapPush(Heap* hp, HPDataType x)// 堆的插入
{
	if (hp->_capacity == hp->_size)
	{
		size_t newcapacity = hp->_capacity * 2;
		hp->_a = (HPDataType*)realloc(hp->_a ,sizeof(HPDataType)* newcapacity);
		hp->_capacity = newcapacity;
	}
	hp->_a[hp->_size] = x;
	hp->_size++;
	Adjustup(hp->_a, hp->_size - 1);
}


