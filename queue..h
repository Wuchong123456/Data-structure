
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <assert.h>

typedef int QDataType ;
// 链式结构：表示队列
typedef struct QListNode
{
	struct QListNode* _pNext;
	QDataType _data;
}QNode;
// 队列的结构
typedef struct Queue
{
	QNode* _front;
	QNode* _rear;
}Queue;

// 初始化队列
void QueueInit(Queue* q);
// 队尾入队列
void QueuePush(Queue* q, QDataType data);
// 队头出队列
void QueuePop(Queue* q);
// 获取队列头部元素
QDataType QueueFront(Queue* q);
// 获取队列队尾元素
QDataType QueueBack(Queue* q);
// 获取队列中有效元素个数
int QueueSize(Queue* q);
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0
int QueueEmpty(Queue* q);
// 销毁队列
void QueueDestroy(Queue* q);
// 打印队列
void PinrtQueue(Queue* q);

void QueueInit(Queue* q)// 初始化队列
{
	q->_front = NULL;
	q->_rear = q->_front;
}

int QueueEmpty(Queue* q)// 检测队列是否为空，如果为空返回非零结果，如果非空返回0
{
	if (q->_front == NULL)
	{
		return 0;
	}
	else
		return 1;
}

void QueuePush(Queue* q, QDataType data) // 队尾入队列
{
	int i = QueueEmpty(q);
	if (i == 0)
	{
		QNode* cur = (QNode*)malloc(sizeof(QNode));
		cur->_data = data;
		cur->_data = NULL;
		q->_front = cur;
		q->_rear = cur;
	}
	else
	{
		QNode* cur = (QNode*)malloc(sizeof(QNode));
		q->_rear->_pNext = cur;
		cur->_data = data;
		cur->_pNext = NULL;
		q->_rear = cur;
	}
	
}
void QueuePop(Queue* q)// 队头出队列
{
	int i = QueueEmpty(q);
	if (i == 0)
	{
		printf("队列为空\n");
		return;
	}
	QNode* cur = q->_front->_pNext;
	free(q->_front);
	q->_front =cur;
}

QDataType QueueFront(Queue* q)// 获取队列头部元素
{
	assert(q);
	return q->_front->_data;
}

QDataType QueueBack(Queue* q)// 获取队列队尾元素
{
	assert(q);
	return q->_rear->_data;
}

int QueueSize(Queue* q)// 获取队列中有效元素个数
{
	assert(q);
	int n = 0;
	QNode* cur = q->_front;
	while (cur != NULL)
	{
		n++;
		cur = cur->_pNext;
	}

	return n;
}


void QueueDestroy(Queue* q)// 销毁队列
{
	assert(q);
	int i = QueueEmpty(q);
	if (i == 0)
	{
		return;
	}
	QNode* cur = NULL;
	while (q->_front)
	{
		cur = q->_front->_pNext;
		free(q->_front);
		q->_front = cur;
	}
	q->_rear = NULL;
	printf("销毁成功\n");
}
void PinrtQueue(Queue* q)
{
	int i = QueueEmpty(q);
	if (i == 0)
	{
		printf("队列为空\n");
		return;
	}
	QNode* cur = q->_front;
	while (cur !=NULL)
	{
		printf("%d ", cur->_data);
		cur = cur->_pNext;
	}
	printf("\n");
}
