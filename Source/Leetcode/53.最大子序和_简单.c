#include<stdio.h>
#include<stdlib.h>
#include"../macro.h" 

int maxSubArray(int* nums, int numsSize)
{
    int max=INT_MIN;
    for(int i=0,sum=0; i<numsSize ;i++){
        if(sum<0)   sum = nums[i];
        else    sum+=nums[i];
        max = max(max,sum);
    }
    return max;
}
//要求固定最小窗口大小，由参数size指定 
int maxSubArray_minsize(int* nums, int numsSize,int size)
{
	int max = INT_MIN;
	int sum=0;
	for(int i=0;i<size-1;i++)	//sum初始值
		sum += nums[i];
	
	/* 每次开始下一轮前presum要有对应值，因为第一次循环对应presum值为0，因此初始化presum=0 */
	for(int presum=0,i=size-1; i<numsSize ;i++){	
		if(presum<0){
			sum -= presum;	//presum为该次循环的窗口其他值(在最小窗口长度外的值)
			presum = nums[i-size+1];	//将presum赋值为下次循环的最大窗口其他值
		}else	
			presum += nums[i-size+1];//将presum赋值为下次循环的最大窗口其他值
		sum += nums[i];	//sum添加新窗口值
		max = max(sum,max);
	}
	return max;
}
int main()
{
	int a[]={-2,5,1,-3,4,-1,2,1,-5,4,6,6};
	int ret = maxSubArray_minsize(a,sizeof(a)/4,3);
	prtd(ret);
}
