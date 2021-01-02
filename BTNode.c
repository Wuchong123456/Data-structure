#include "BTNode.h"

int BinaryTreeLeve1KSize(BTNode* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}
	if (k==1)
	{
		return 1;
	}
	return BinaryTreeLeve1KSize(root->_left, k - 1) + BinaryTreeLeve1KSize(root->_right, k - 1);

}
int BinaryTreeSize(BTNode* root)
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
int BinaryTreeHight(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	int leftDepth = BinaryTreeHight(root->_left);
	int rightDepth = BinaryTreeHight(root->_right);
	return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}
