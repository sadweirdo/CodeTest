#include<stdio.h>
#include<stdlib.h>
#include"../macro.h"
#include"../string.h"
int mySqrt(int x)
{
    int i;
    for(i=0;i*i<x && i<46340;i++);//防止i*i溢出，因此循环结束时i不能大于46340
    if(i*i>x) return i-1;
    return i;
}
/*		二分查找		*/
int mySqrt(int x)
{
    int low=0,high = 46340;
    while(low<=high){
        int mid = (low+high)/2;
        if(mid*mid==x)  return mid;
        if(mid*mid<x)   low = mid+1;
        else    high = mid-1;
    }
    return high;
}