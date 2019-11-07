#include"../macro.h"
#include"../hash.h"

int* twoSum(int* nums, int numsSize, int target, int* returnSize) 
{
	*returnSize = 0;
    if(numsSize<2)	return NULL;
	int *ret=calloc(sizeof(int),2);
	int max = 0;
	for(int i=0,tmp;i<numsSize;i++){
		tmp = nums[i]<0?-nums[i]:nums[i];
		max = max(tmp,max);
		tmp = target - nums[i];
		max = max(tmp,max);
	}
    int *hash = orihash_init(max+1);
    for(int i=0,tmp;i<numsSize;i++){
    	tmp = target - nums[i];
    	if(ret[0] = orihash_find(hash,tmp)){
    		ret[0]--;
    		ret[1] = i;
    		*returnSize =2;
    		return ret;
		}
		else
			orihash_add(hash,nums[i],i+1);
	}
	return NULL;
}
int main()
{
	int size;
	int num[3]={3,2,3};
	int *ret = twoSum(num,3,6,&size);
	printf("[%d, %d]\n",ret[0],ret[1]);
}
