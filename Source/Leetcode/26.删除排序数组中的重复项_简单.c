#include"../macro.h"
/* 只需修改数组前列元素使其均不相等即可，例如 0 0 0 这类数组就不必修改直接返回 */ 
int removeDuplicates(int* nums, int numsSize)
{
    if(!numsSize)   return 0;
    
    int index=0;
    for(int i=1;i<numsSize;i++){
        if(nums[i]!=nums[index])
            nums[++index] = nums[i];
    }
    return index+1;
}
/* 个人最初版 */
int removeDuplicates(int* nums, int numsSize)
{
    if(!numsSize)   return 0;
    
    int index=0;//最初定义了prev = nums[index]
    int count = 1;
    for(int i=1;i<numsSize;i++){
        if(nums[i]!=nums[index])   continue;
        nums[++index] = nums[i];
        count++;
    }
    return count;
}