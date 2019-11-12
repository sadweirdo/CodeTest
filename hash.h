#include<stdlib.h>
#include<memory.h>
typedef struct{
	char flag;
	int val;
}orihash;
#define ORIHASH_EXIST 0x01
#define orihash_isexist(hash,key)	(hash[key]->flag & ORIHASH_EXIST)
static inline orihash * orihash_init(int num)
{
	if(num<=0)	return NULL;
	orihashnum = num;
	orihash * ret = (orihash *)malloc(orihashnum*sizeof(orihash));
	memset(ret,0,orihashnum*sizeof(orihash));
	return ret;
} 
static inline int orihash_add(orihash *hash ,int key ,int val)
{
	if(orihash_isexist(hash,key)){
		printf("Error:hash exist,add fail.\n");
		return 1;
	}
	hash[key]->val=val;
	hash[key]->flag |= ORIHASH_EXIST;
	return 0;
}
static inline int orihash_find(orihash *hash ,int key ,int *val)
{
	if(!orihash_isexist(hash,key))	return 1;
	else *val = hash[key]->val;
	return 0;
}
static inline int orihash_remove(orihash *hash ,int key)
{
	if(!orihash_isexist(hash,key){
		printf("Warning:key does not in hashtable");
		return 1;
	}
	hash[key]->flag &= ~ORIHASH_EXIST;
	return 0;
}
