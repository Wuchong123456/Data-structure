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
	else
	{
		return 0;
	}
	return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right);
}
