#include"../macro.h"
int removeElement(int* nums, int numsSize, int val){
    if(numsSize == 0)   return 0;
    int i=0,j=numsSize-1;
    int tmp;
    while(i<j){
        if(nums[i]==val){
            exchange(nums[i],nums[j],tmp);
            j--;
        }
        else    i++;
    }
    if(nums[i]==val) return i;
    else return i+1;
}