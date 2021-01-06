#define  _CRT_SECURE_NO_WARNINGS 1
#include "BTNode.h"

BTNode* _BinaryTreeCreate(BTDataType* Aret, int Size, int* pi)
{
	BTNode* root = NULL;
	if (*pi>Size)
	{
		return root;
	}
	if (Aret[*pi] != '#')
	{
	    root = malloc(sizeof(BTNode));
		root->_data = Aret[*pi];
		(*pi)++;
		root->_left = _BinaryTreeCreate(Aret,Size,pi);
		root->_right = _BinaryTreeCreate(Aret, Size, pi);
	}
	else
	{
		(*pi)++;
		return NULL;
	}
	return root;
}


BTNode* BinaryTreeCreate()// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
{
	int i = 0;
	BTDataType arr[] = "ABD##E#H##CF##G##";
	int Size = strlen(arr);
	BTDataType* Aret = malloc(sizeof(BTDataType)*Size);
	strcpy(Aret, arr);
	int* pi = &i;
	BTNode* root =  _BinaryTreeCreate(Aret,Size,pi);
	
	return root;
}
int BinaryTreeDestory(BTNode* root)// 二叉树节点个数
{
	if (root == NULL)
	{
		return 0;
	}

	return 1+BinaryTreeDestory(root->_left)+BinaryTreeDestory(root->_right);
}
int BinaryTreeSize(BTNode* root)// 二叉树叶子节点个数
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->_left == NULL && root->_right == NULL)
	{
		return 1;
	}
	
	return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right);
}
int BinaryTreeLevelKSize(BTNode* root, int k)// 二叉树第k层节点个数
{
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}

BTNode* BinaryTreeFind(BTNode* root, BTDataType x)// 二叉树查找值为x的节点
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->_data == x)
	{
		return root;
	}
	BTNode* Left = BinaryTreeFind(root->_left, x);
	if (Left == NULL)
	{
		BTNode* Right = BinaryTreeFind(root->_right, x);
		return Right;

	}
	return Left;
}
void _BinaryTreePrevOrder(BTNode* root,int* arr,int* i)//前序遍历
{
	
	if (root == NULL)
	{
		return;
	}
	else
	{
		arr[*i] = root->_data;
		(*i)++;
		_BinaryTreePrevOrder(root->_left, arr,i);
		_BinaryTreePrevOrder(root->_right, arr, i);
	}
	
}

void _BinaryTreeInOrder(BTNode* root, int* arr, int* i)// 二叉树中序遍历
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		_BinaryTreeInOrder(root->_left, arr, i);
		arr[*i] = root->_data;
		(*i)++;
		_BinaryTreeInOrder(root->_right, arr, i);	
	}

}

void BinaryTreePrevOrder(BTNode* root)// 二叉树前序遍历
{
	int Size = BinaryTreeSize(root);
	int* arr = malloc(sizeof(int)*Size);
	int i = 0;
	_BinaryTreePrevOrder(root, arr, &i);
	for (i=0; i < Size; i++)
	{
		printf("%c ", arr[i]);
	}
	printf("\n");
	_BinaryTreeInOrder(root, arr, &i);
	for (i = 0; i < Size; i++)
	{
		printf("%c ", arr[i]);
	}
}
