#include"../macro.h"
int removeElement(int* nums, int numsSize, int val)
{
    if(numsSize == 0)   return 0;
    int i=0,tail=numsSize-1;
    while(i<=tail){
        if(nums[i]==val)
            nums[i] = nums[tail--];
        else    i++;
    }
    return i;
}