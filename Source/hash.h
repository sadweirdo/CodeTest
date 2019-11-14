#include<stdlib.h>
#include<stdio.h>
#include<memory.h>

struct hashelement{
	char flag;
	int val;
};

typedef struct hashelement** Hashtable;

#define HASH_EXIST 0x01
#define HASH_MAXSIZE 4096

#define POSITIVEINT 0x7FFFFFFF
#define hash_isexist(hashtable,index)    (hashtable[index]->flag & HASH_EXIST)
static inline int hash(int key)
{
	long long num = key;
	return (int)(((num*31) & POSITIVEINT) % HASH_MAXSIZE);
}

#define DECLARE_HASH(name)	Hashtable name = hash_init();
static inline Hashtable hash_init()
{
	Hashtable ret;
	ret = (Hashtable)malloc(HASH_MAXSIZE*sizeof(struct hashelement *));
	memset(ret,0,HASH_MAXSIZE*sizeof(struct hashelement *));
	return ret;
} 

static inline int hash_add(Hashtable hashtable ,int key ,int val)
{
    int index = hash(key);
	if(!hashtable[index])	hashtable[index] = (struct hashelement *)malloc(sizeof(struct hashelement));
	else if(hash_isexist(hashtable,index)){
		printf("Warning:Key:[%d]-Val:[%d] is exist,Val:[%d] add fail.\n",key,hashtable[index]->val,val);
		return 1;
	}
	
	hashtable[index]->val=val;
	hashtable[index]->flag |= HASH_EXIST;
	return 0;
}

static inline int hash_mod(Hashtable hashtable ,int key ,int val)
{
    int index = hash(key);
	if(!hashtable[index] || !hash_isexist(hashtable,index)){
		printf("Error:key does not in hashtable");
		return 1;
	}
	
	hashtable[index]->val=val;
	return 0;
} 

static inline int hash_remove(Hashtable hashtable ,int key)
{
     int index = hash(key);
	if(!hashtable[index] || !hash_isexist(hashtable,index)){
		printf("Warning:key does not in hashtable");
		return 0;
	}
	hashtable[index]->flag &= ~HASH_EXIST;
	return 0;
}

static inline int hash_find(Hashtable hashtable ,int key ,int *val)
{
    int index = hash(key);
	if(!hashtable[index] || !hash_isexist(hashtable,index))	return 0;
	else if(val)    *val = hashtable[index]->val;
	return 1;
}
