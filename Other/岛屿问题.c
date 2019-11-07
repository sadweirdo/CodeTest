#include"../macro.h"

int uni_find(int *nums,int n)
{
	if (nums[n]==n)
		return n;
	else if(nums[n]<0)
		return -1;
	return uni_find(nums,nums[n]);
}
int isuni(int * nums,int x,int y)
{
	int a = uni_find(nums,x);
	int b = uni_find(nums,y);
	if(a==b&&a>=0&&b>=0)	return 1;
    else return 0;
}

void uni_add(int * nums,int x,int y)
{
	int a = uni_find(nums,x);
	int b = uni_find(nums,y);
	if(a!=b&&a>=0&&b>=0)	nums[a]=b;
}

int vec[4][2]={{0,1},{-1,0},{0,-1},{1,0}};
#define tran(a,b) ((a)*cow + (b))
#define index_ok(x,y,z) ((x)>=0 && (y)>=0 && z<numsize)
#define isexist(x) (num[x]>=0)

int lanspace()
{
	IN 		int cow,line,pnumber;
				scanf("%d",&line);
				scanf("%d",&cow);
				scanf("%d",&pnumber);	
	
    IN 		int numsize = cow*line;
	IN 		int num[numsize];
	REFIN 	int i;
				for(i=0;i<numsize;i++)	num[i]=-1;
	
	IN 		int xy[pnumber][2]; 
				for(i=0;scanf("%d%d",&xy[i][0],&xy[i][1])!=EOF;i++);

	OUT 	int count=0;
	
	for(i=0;i<pnumber;i++){	
		int x=xy[i][0], y=xy[i][1], index=tran(x,y);
	
		if(index_ok(x,y,index) && !isexist(index)){
			num[index]=index;
			count++;
		}
		for(int j=0;j<4;j++){	
			int tmpx = (x + vec[j][0])%line , tmpy = (y + vec[j][1])%cow;
			int tmpindex = tran(tmpx,tmpy);
			
			if(index_ok(tmpx,tmpy,tmpindex))
				if(isexist(tmpindex) && !isuni(num, tmpindex, index)){
					uni_add(num , tmpindex , index);
					count --;
				}
		}
		printf("%d%c",count,i==pnumber-1?' ':0);
	}	
 } 
 

