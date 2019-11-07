#include "../macro.h"
typedef struct TreeNode{
    int val;
    struct TreeNode *left,*right;
}tree;
#define TYPEC struct TreeNode *
#include"../array.h"
void itration(tree *root)
{
    if(!root)    return;
    if(root->val==-1) {
	printf("# ");
	return;
	}
    printf("%d ",root->val);
    itration(root->left);
    itration(root->right);
}
#define mloc(TYPE) (TYPE *)malloc(sizeof(TYPE))
#define inittree(root) ({(root)->val=0;(root)->left=NULL;(root)->right=NULL;})
int main()
{
    int numsizes;
    scanf("%d",&numsizes);
    char num[numsizes];
    for(int i=0;i<numsizes;i++){
    	getchar();
        scanf("%c",&num[i]);
        if(num[i]=='#')	num[i]=-1;
        else
        	num[i]-='0';
	}
    
    
    for(int i=0;i<numsizes;i++){
    	prtd(num[i]);
	}
    tree *root = mloc(tree);
    inittree(root);
    tree *tmp = NULL;
    int index=0;
    
    Queue *que = queue_init(numsizes*3);
    queue_add(que,root);
    while(queue_next(que) && index<numsizes){
	queue_prt_hex(que);
        queue_remove(que,&tmp);
        tmp->val = num[index++];
        if(tmp->val ==-1)    continue;
        tmp->left = mloc(tree);
        inittree(tmp->left);
        queue_add(que,tmp->left);
        tmp->right = mloc(tree);
        inittree(tmp->right);
        queue_add(que,tmp->right);
    }
    itration(root);
}
