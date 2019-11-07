#include"../macro.h"
/* 只需修改数组前列元素使其均不相等即可，例如 0 0 0 这类数组就不必修改直接返回 */ 
int removeDuplicates(int* nums, int numsSize)
{
    if(numsSize ==0 ) return 0;
    int i,j;
	for(i=0,j=0;j<numsSize;j++)
		if(nums[j]!=nums[i])	nums[++i]= nums[j];
	return i+1;
}
