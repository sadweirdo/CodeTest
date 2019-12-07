#include<stdio.h>
#include<stdlib.h>
#include"../macro.h"
#include"../string.h"
bool isSymmetricTree(struct TreeNode* p, struct TreeNode* q){
    if(p==q)    return 1;
    if(p==NULL || q==NULL)  return 0;
    if(p->val != q->val)    return 0;
    return isSymmetricTree(p->left,q->right) && isSymmetricTree(p->right,q->left);
}

bool isSymmetric(struct TreeNode* root){
    if(!root) return 1;
    return isSymmetricTree(root->left,root->right);
}