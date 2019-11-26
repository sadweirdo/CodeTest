#include<stdio.h>
#include<stdlib.h>
#include"../macro.h"

/* 推荐二分法 */
int searchInsert(int* nums, int numsSize, int target)
{
    if(numsSize ==0)    return 0;
    int low = 0, high = numsSize-1;
    
    while(low <= high){
        int mid = (low+high)/2;
        if(nums[mid] == target)
            return mid;
        if(nums[mid] < target)
            low = mid +1;
        else
            high = mid-1;
    }
    return low;
}

/* 另一种二分法 */
int searchInsert(int* nums, int numsSize, int target)
{
    if(numsSize ==0)    return 0;
    int low = 0, high = numsSize-1;
    
    while(low < high){
        int mid = (low+high)/2;
        if(nums[mid] == target)
            return mid;
        if(nums[mid] < target)
            low = mid +1;
        else
            high = mid;
    }
    if(nums[low] < target)  return low+1;
    return low;
}

