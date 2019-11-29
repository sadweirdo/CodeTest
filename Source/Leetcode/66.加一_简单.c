#include<stdio.h>
#include<stdlib.h>
#include"../macro.h"
#include"../string.h"
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize)
{
    for(int i =digitsSize-1;i>=0;i--){
        if( digits[i] = (digits[i]+1)%10 ){
            break;
        }
    }
    *returnSize = digits[0]?digitsSize:digitsSize+1;
    int *ret = (int *)calloc(*returnSize,sizeof(int));
    if(!digits[0])  ret[0]=1;
    for(int i=0;i<digitsSize;i++)
        ret[*returnSize-1-i] = digits[digitsSize-1-i];
    return ret;
}