#include"../macro.h"
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
 };
 
struct TreeNode* buildTree(int* preorder, int preorder_size, int* inorder, int inorder_size) {
	
    if(preorder_size==0 || inorder_size==0 || preorder_size!=inorder_size)
    	return NULL;
    	
    int i=0;   
    OUT struct TreeNode *tree = mloc(struct TreeNode);
    tree->left=NULL;
    tree->right=NULL;
    tree->val = preorder[0];

    while(i<inorder_size){
    	if(inorder[i]==preorder[0])		break;
    	else											i++;
	}
	tree->left = buildTree(preorder+1,i,inorder,i);
	tree->right = buildTree(preorder+1+i,preorder_size-i-1,inorder+i+1,inorder_size-i-1); 
	return tree;    
}