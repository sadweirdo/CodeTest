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
//Ҫ��̶���С���ڴ�С���ɲ���sizeָ�� 
int maxSubArray_minsize(int* nums, int numsSize,int size)
{
	int max = INT_MIN;
	int sum=0;
	for(int i=0;i<size-1;i++)	//sum��ʼֵ
		sum += nums[i];
	
	/* ÿ�ο�ʼ��һ��ǰpresumҪ�ж�Ӧֵ����Ϊ��һ��ѭ����ӦpresumֵΪ0����˳�ʼ��presum=0 */
	for(int presum=0,i=size-1; i<numsSize ;i++){	
		if(presum<0){
			sum -= presum;	//presumΪ�ô�ѭ���Ĵ�������ֵ(����С���ڳ������ֵ)
			presum = nums[i-size+1];	//��presum��ֵΪ�´�ѭ������󴰿�����ֵ
		}else	
			presum += nums[i-size+1];//��presum��ֵΪ�´�ѭ������󴰿�����ֵ
		sum += nums[i];	//sum����´���ֵ
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
