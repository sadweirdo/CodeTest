#include"../macro.h"
int iteratesearch(int *num,int low,int high,int target,int *ret)
{
	int left = low, right = high;
	if(!num || low>high)	return 1;
	while(left<=right){
		int mid = (left+right)/2;
		if(num[mid]==target){
			*ret = mid;
			return 0;
		}
		else if(num[mid]>target)
			right = mid-1;
		
		else
			left = mid+1;
	}	
	*ret = left;
	return 0;
} 
int searchInsert(int* nums, int numsSize, int target)
{
    int index,rc;
    rc = iteratesearch(nums,0,numsSize-1,target,&index);
    if(rc)   return 0;
    else return index;
}
void binarysearch(int *num,int low,int high,int target,int *ret)
{
	*ret = low;
    if(low>high)    return 0;
    int mid = (low+high)/2;
    int ret = 0;
    if(num[mid]==target) {
    	*ret = mid;
    	return;
	}
    else if(num[mid]>target)
        binarysearch(num,low,mid-1,target,ret);
    else
        binarysearch(num,mid+1,high,target,ret);
}
int searchInsert(int* nums, int numsSize, int target)
{
    int index,insert;
    binarysearch(nums,0,numsSize-1,target,&insert);
	return insert;
}
