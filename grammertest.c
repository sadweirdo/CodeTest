#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int physical;
	struct node *next;
}LinkList,*pLinkList;//��C�ִ���ʱ����C++������&

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
	printf("û���ҵ��ýڵ㣡\n");
}

void zeng(pLinkList pl)
{
	pLinkList l=(pLinkList)malloc(sizeof(LinkList));
	
	printf("����������ɼ���");
	scanf("%d",&l->physical);
	
	l->next=pl->next;
	pl->next=l;
}

void DaYinLianBiao(pLinkList pl)
{
	while(pl!=NULL)
	{
		printf("�ɼ���%d ",pl->physical);
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
	pLinkList L=NULL; //Ϊ�˽�Լ�ڴ�ͷ����������ڵ㣬��Ҫ�õ��ڴ�ռ䣬һ��ʹ��ָ���malloc()�����ڴ����ʵ�ʱ���

	chushihua(&L);  //��ͷ�ڵ���в���
	
	printf("ͷ�ڵ㣺L->physical=%d\n",L->physical);
	
	printf("���������ӽڵ������");
	scanf("%d",&length);
	
	while(length--)
	{
		zeng(L);
	}
	
	DaYinLianBiao(L);
	printf("\n��������Ҫɾ���Ľڵ�ķ���(ͷ�ڵ㲻��ɾ��)��");
	scanf("%d",&score);
	shanchu(L,score);
	printf("����Ϊ��\n");
	DaYinLianBiao(L);
	
	system("pause");
	return 0;
}
