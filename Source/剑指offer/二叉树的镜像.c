#include"../macro.h"
typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
 }Tree;
 
Tree * mirrortree_rebuild(Tree *root)
{
	if(root == NULL)	return NULL;
	
	OUT	Tree *t = mloc(Tree);
		t->val = root->val;
		t->left = mirrortree_rebuild(root->right);
		t->right = mirrortree_rebuild(root->left);
	
	return t;
}

int mirrortree_mirror(Tree *root)
{
	if(root == NULL)	return NULL;
	
	REFIN	Tree *tmp;
	
	mirrortree_mirror(root->left);
	mirrortree_mirror(root->right);
	
	exchange(root->left,root->right,tmp);
	
	return t;
}

int main()
{

}

