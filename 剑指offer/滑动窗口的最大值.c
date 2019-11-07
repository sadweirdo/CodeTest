#include"../macro.h"
#include<string.h>
typedef struct{
	int size;
	int len;
	int start;
	int end;
	int *queue;
}Queue;

static inline int queue_remove(Queue *que,int *ret)
{
	int rc=1;
	if(que->start==que->end)	return rc;
	
	if(ret)	*ret = que->queue[que->start];
	que->start=(que->start + 1) % (que->len); 
	que->size--;
	rc=0;
	return rc;
} 

static inline int queue_add(Queue *que,int num)
{
	int rc=1;
	if(que->size==que->len)	return rc;
		
	que->queue[que->end] = num;
	que->end = (que->end + 1) % (que->len);
	que->size++;
	rc=0;
	return rc;
}

static inline int queue_add_compare(Queue *que,int num)
{
	int rc=0;
	int index = (que->end+que->len-1)%(que->len);
	
	if(que->size==que->len && que->queue[index]>num)	return rc;
	
	if(que->end==que->start)
		return !(queue_add(que,num));
	
	if(que->queue[index] >= num){	
		que->queue[que->end] = num;
		que->end = (que->end + 1) % (que->len);
		que->size++;
		rc = 1;
		return rc;
	}
	while((que->end!=que->start) && (que->queue[index]<num)){
		que->end = index;
		index = (que->end+que->len-1)%(que->len);
		que->size--;
	}
	rc = !(queue_add(que,num));
	return rc;
}

void prtqueue(Queue *que){
	prt(size[%d] start[%d] end[%d]\n,que->size,que->start,que->end);
	for(int i=0;i<que->len;i++)
		prt(%d\t,que->queue[i]);
	Pline;
}

int* maxInWindows(int* nums, int numsSize, int k, int* returnSize) 
{
	if(numsSize==0 || k==0){
		*returnSize = 0;
		return NULL;
	}

    DATAS	Queue que={0,k,0,0,NULL};
    		que.queue=mlloc(int,k);
    		memset(que.queue,0,k*sizeof(int));
   
    REFO	int size = numsSize-k+1;
    OUT		*returnSize = size;
    OUT		int *ret = mlloc(int,size);
    
    for(int i=0;i<numsSize;i++){
    	if(que.size==k)
    		queue_remove(&que,NULL);
    	queue_add_compare(&que,nums[i]);
    prt(newnum[%d]:[%d] ,i,nums[i]);
	prtqueue(&que);
    	if(i>=k-1)
    		ret[i-k+1]=que.queue[0];
	}
    return ret;
} 
int main()
{
	int *number,numbersize;
	int a[8]={2,3,4,2,6,2,5,1};
	number = maxInWindows(a,8,3,&numbersize);
	for(int i=0;i<numbersize;i++)
		prt(%d\t,number[i]);

}
