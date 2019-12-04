#include<stdio.h>
#include<stdlib.h>
#include"../macro.h"
#include"../string.h"

#define TYPEC int
#include"../array.h"

int isValid(char * s)
{
    int hash[128]={0};
	hash['('] = hash[')'] = 1;
	hash['['] = hash[']'] = 2;
	hash['{'] = hash['}'] = 3;
	
	int num = str_len(s);
	if(!num)   return 1;
	Stack *stack = stack_init(num);
	for(int i = 0 ;i < num ;i++){
		if(s[i] == ')' || s[i] == ']' || s[i] == '}'){
			if(stack_next(stack) != hash[s[i]])
				return 0;
			stack_remove(stack,NULL);
		}else
			stack_add(stack,hash[s[i]]);
	}
	if(stack_size(stack))  return 0;
	return 1;
}
/*	优化哈希 */
int isValid(char * s)
{
    int hash[128]={0};
	hash[')'] = '(';
	hash[']'] = '[';
	hash['}'] = '{';
	
	int num = str_len(s);
	if(!num)   return 1;
	Stack *stack = stack_init(num);
	for(int i = 0 ,tmp;i < num ;i++){
		if(hash[s[i]] && stack_next(stack) == hash[s[i]])
			stack_remove(stack,NULL);
		else
			stack_add(stack,s[i]);
	}
	if(stack_size(stack))  return 0;
	return 1;
}
int main()
{
    char *s="";
    prtd(isValid(s)); 
}
