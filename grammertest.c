#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int physical;
	struct node *next;
}LinkList,*pLinkList;//纯C手打，暂时抛弃C++的引用&

void shanchu(pLinkList pl,int score)
{
	pLinkList pre=pl,l=pl->next;
    while(l!= NULL)
    {
        if(l->physical==score)
        {
			pre->next=l->next;
			free(l);
			return;
		}
		pre=l;
		l=l->next;
	}
	printf("没有找到该节点！\n");
}

void zeng(pLinkList pl)
{
	pLinkList l=(pLinkList)malloc(sizeof(LinkList));
	
	printf("请输入物理成绩：");
	scanf("%d",&l->physical);
	
	l->next=pl->next;
	pl->next=l;
}

void DaYinLianBiao(pLinkList pl)
{
	while(pl!=NULL)
	{
		printf("成绩：%d ",pl->physical);
		pl=pl->next;
	}
}

void chushihua(pLinkList *p)
{
	*p=(pLinkList)malloc(sizeof(LinkList));
	
	(*p)->physical=60;
	
	(*p)->next=NULL;
}

int main()
{
	int length,score;
	pLinkList L=NULL; //为了节约内存和方便销毁链节点，凡要用到内存空间，一律使用指针加malloc()申请内存代替实际变量

	chushihua(&L);  //对头节点进行操作
	
	printf("头节点：L->physical=%d\n",L->physical);
	
	printf("请输入增加节点个数：");
	scanf("%d",&length);
	
	while(length--)
	{
		zeng(L);
	}
	
	DaYinLianBiao(L);
	printf("\n请输入你要删除的节点的分数(头节点不能删除)：");
	scanf("%d",&score);
	shanchu(L,score);
	printf("链表为：\n");
	DaYinLianBiao(L);
	
	system("pause");
	return 0;
}
