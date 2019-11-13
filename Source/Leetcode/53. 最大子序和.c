#include"../macro.h" 
int maxSubArray(int* nums, int numsSize){
	int max = INT_MIN;
	int head,tail;
	int sum;
	for(tail=sum=0;tail<numsSize;tail++){
		if(sum<=0)
			sum = nums[tail];
		else
			sum += nums[tail];
		if(sum > max)	max = sum;
	} 
	return max;
}
//要求固定最小窗口大小，由参数size指定 
int maxSubArray_minsize(int* nums, int numsSize,int size){
	int max = INT_MIN;
	int head,tail;
	int preval,sum=0;
	
	for(int i=0;i<size-1;i++)
		sum += nums[i];
		
	for(tail=size-1,head=0,preval=0;tail<numsSize;tail++,head++){
		
		sum += nums[tail];
		
		if(preval<0){
			sum = sum - preval;
			preval = nums[head];
		}
		else
			preval += nums[head];
				
		if(sum > max)	max = sum;
	} 
	return max;
}
int main()
{
	int a[]={-2,5,1,-3,4,-1,2,1,-5,4,6,6};
	int ret = maxSubArray_minsize(a,sizeof(a)/4,3);
	prtd(ret);
}
