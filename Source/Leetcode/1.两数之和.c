#include"../macro.h"
#include"../hash.h"

int* twoSum(int* nums, int numsSize, int target, int* returnSize) 
{
    if(numsSize<2)  goto FAILED;
    
    *returnSize =2;

	int *ret=calloc(sizeof(int),2);
	int max = 0;
    
    /* 遍历得到最大绝对值作为哈希表长度初始化哈希表 */ 
	for(int i=0,tmp;i<numsSize;i++){
		tmp = nums[i]<0?-nums[i]:nums[i];
		tmp = max(tmp,target);
		max = max(tmp,max);
	}
    orihash *hash = orihash_init(max);
    
    for(int i=0,tmp;i<numsSize;i++){
    	tmp = target - nums[i];
    	if(orihash_find(hash,tmp,ret)){  //ret为输出的第一个坐标索引值 
    		ret[1] = i;
    		return ret;
		}
		else if(orihash_add(hash,nums[i],i)){    //将坐标索引值作为键值存储                 
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
	int num[7]={3,2,3,23,64,4,125};
	int *ret = twoSum(num,7,67,&size);
	printf("[%d, %d]\n",ret[0],ret[1]);
}
