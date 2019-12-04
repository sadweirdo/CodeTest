#include<stdio.h>
#include<stdlib.h>
#include"../macro.h"
#include"../hash.h"
int* twoSum(int* nums, int numsSize, int target, int* returnSize) 
{
    if(numsSize<2)  goto FAILED;
    *returnSize =2;

	int *ret=calloc(sizeof(int),2);
	int max = 0;
    
    DECLARE_HASH(ht);
    for(int i=0,tmp;i<numsSize;i++){
    	tmp = target - nums[i];
    	if(hash_find(ht,tmp,ret)){  //ret为输出的第一个坐标索引值 
    		ret[1] = i;
    		return ret;
		}
		else if(hash_add(ht,nums[i],i)){    //将坐标索引值作为键值存储                 
            prt(Error:Add Hashtable Fail);
            break;
        }
	}
FAILED:
	*returnSize = 0;
	return NULL;
}

int main()
{
	int size;
	int num[]={-3,4,3,90};
	int *ret = twoSum(num,4,0,&size);
	printf("[%d, %d]\n",ret[0],ret[1]);
}
