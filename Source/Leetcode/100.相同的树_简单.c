#include<stdio.h>
#include<stdlib.h>
#include"../macro.h"
#include"../string.h"

bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if(p==q)    return 1;
    if(p==NULL || q==NULL)  return 0;
    if(p->val != q->val)    return 0;
    return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
}