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
int BinaryTreeSize(struct TreeNode* root)
 {
     if(root == NULL)
     {
         return 0;
     }
     
     return 1 + BinaryTreeSize(root->left)+BinaryTreeSize(root->right);
 }
 void _preorderTraversal(struct TreeNode* root,int* retA,int* pi)
 {
     if(root== NULL)
     {
         return;
     }
     retA[(*pi)++]= root->val;
     _preorderTraversal(root->left,retA,pi);
     _preorderTraversal(root->right,retA,pi);
 }
int* preorderTraversal(struct TreeNode* root, int* returnSize){
    int size = BinaryTreeSize(root);
    int* retA = malloc(sizeof(int)*size);
    *returnSize = size;
    int i = 0;
    _preorderTraversal(root,retA,&i);

  return retA;
}
