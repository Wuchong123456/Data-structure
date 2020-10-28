#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
typedef int STDataType;
//
//typedef struct Stack
//{
//	STDataType* List;
//	int _top; // 栈顶
//}Stack;
// 支持动态增长的栈
typedef int STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top; // 栈顶
	int _capacity; // 容量
}Stack;
// 初始化栈
void StackInit(Stack* ps);
// 入栈
void StackPush(Stack* ps, STDataType data);
// 出栈
void StackPop(Stack* ps);
// 获取栈顶元素
STDataType StackTop(Stack* ps);
// 获取栈中有效元素个数
int StackSize(Stack* ps);
// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0
int StackEmpty(Stack* ps);
// 销毁栈
void StackDestroy(Stack* ps);
//打印栈
void PrintfStack(Stack* ps);



void StackInit(Stack* ps)// 初始化栈
{
	ps->_a = (STDataType*)malloc(2*sizeof(STDataType));
	if (ps->_a == NULL)
	{
		printf("StackInint:%s\n", strerror(errno));
	}
	ps -> _top = 0;
	ps-> _capacity = 2;
}
Stack* OpenCapacity(Stack* ps)//增容程序
{
	ps->_a = (STDataType*)realloc(ps->_a, 2 * ps->_capacity*sizeof(STDataType));
	if (ps->_a == NULL)
	{
		printf("OpenCapacity:%s\n", strerror(errno));
	}
	ps->_capacity = ps->_capacity * 2;
	return ps;
}
int StackEmpty(Stack* ps)// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0
{
	if (ps->_top == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

void StackPush(Stack* ps, STDataType data)// 入栈
{
	if (ps->_capacity == ps->_top)
	{
		ps = OpenCapacity(ps);
	}
	ps->_a[ps->_top] = data;
	ps->_top++;
}

void StackPop(Stack* ps)// 出栈
{
	int a = StackEmpty(ps);
	if (a == 0)
	{
		printf("栈为空\n");
		return;
	}
	else
	{
		
		ps->_top--;
	}	
}

STDataType StackTop(Stack* ps)// 获取栈顶元素
{
	int a = StackEmpty(ps);
	if (a == 0)
	{
		printf("栈为空\n");
	}
	
		return  ps->_a[ps->_top-1];
	
}

int StackSize(Stack* ps)// 获取栈中有效元素个数
{
		return ps->_top;
}

void StackDestroy(Stack* ps)// 销毁栈
{
	if (ps == NULL || ps->_a == NULL)
	{
		return;
	}
	else
	{
		free(ps->_a);
		ps->_a = NULL;
		ps->_capacity = 0;
		ps->_top = 0;
	}
}
void PrintfStack(Stack* ps)
{
	int a = StackEmpty(ps);
	if (a == 0)
	{
		printf("栈为空\n");
		return;
	}
	else
	{
		int n = ps->_top;
		while (n--)
		{
			printf("%d ", ps->_a[n]);
		}
		printf("\n");
	}
	
}
