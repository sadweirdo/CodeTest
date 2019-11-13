#include<stdlib.h>
#include<memory.h>
typedef struct{
	char flag;
	int val;
}orihash;
#define ORIHASH_EXIST 0x01
#define orihash_isexist(hash,key)	(hash[key].flag & ORIHASH_EXIST)
static int orihashlength;

static inline orihash * orihash_init(int num)
{
	if(num<=0)	return NULL;
	orihashlength = num;
	orihash * ret = (orihash *)malloc(orihashlength*sizeof(orihash));
	memset(ret,0,orihashlength*sizeof(orihash));
	return ret;
} 
static inline int orihash_add(orihash *hash ,int key ,int val)
{
    key %= orihashlength;
	if(orihash_isexist(hash,key)){
		printf("Warning:Key:[%d]-Val:[%d] is exist,Val:[%d] add fail.\n",key,hash[key].val,val);
		return 0;
	}
	hash[key].val=val;
	hash[key].flag |= ORIHASH_EXIST;
	return 0;
}
static inline int orihash_remove(orihash *hash ,int key)
{
    key %= orihashlength;
	if(!orihash_isexist(hash,key)){
		printf("Warning:key does not in hashtable");
		return 1;
	}
	hash[key].flag &= ~ORIHASH_EXIST;
	return 0;
}
static inline int orihash_find(orihash *hash ,int key ,int *val)
{
    key %= orihashlength;
	if(!orihash_isexist(hash,key))	return 0;
	else if(val)    *val = hash[key].val;
	return 1;
}
