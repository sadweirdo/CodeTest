#include<stdlib.h>
#include<memory.h>
static int orihashnum=0;
static inline int * orihash_init(int num)
{
	if(num<=0)	return NULL;
	orihashnum = num;
	int * ret = (int *)malloc(2*num*sizeof(int));
	memset(ret,0,2*num*sizeof(int));
	return ret;
} 
static inline int orihash_add(int *hash,int key,int val)
{
	key+=orihashnum;
	if(hash[key]){
		printf("Error:hash exist,add fail.\n");
		return 1;
	}
	if(val) hash[key]=val;
	else hash[key]=1;
	return 0;
}
static inline int orihash_find(int *hash,int key)
{
	key+=orihashnum;
	if(key<0)	return 0;
	return hash[key];
}
static inline int orihash_remove(int *hash,int key)
{
	key+=orihashnum;
	if(key <0)	return 1;
	hash[key]=0;
	return 0;
}
