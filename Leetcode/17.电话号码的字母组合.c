#include"../macro.h"
#include<string.h>
#define TYPEC char *
#include "../array.h"

char *KEY[] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
char *head(Queue *que)
{
	char *ret = queue_next(que);
	if(!ret)	return "";
	return ret; 
}
char * addchar(char *str,char c)
{
	int size = str?strlen(str):0;
	char * n = mlloc(char,size+2);\
	if(str)	memcpy(n,str,size);
	n[size]=c;
	n[size+1]='\0';
	return n; 
}
char ** letterCombinations(char * digits, int* returnSize)
{
	if(!digits){
		*returnSize = 0;
		return NULL;
	}
	
	int size = strlen(digits);
	if(!size){
		*returnSize = 0;
		return NULL;
	}
	
	Queue *que = queue_init(300);
	
	for(int i=0;i<size;i++){
		int cnt = que->size,index = digits[i]-'0';
		char *tmp = NULL,*str = NULL;
		while(strlen(head(que)) == i){
			queue_remove(que,&tmp);
			for(int j=0;j<strlen(KEY[index]);j++){
				str = addchar(tmp,KEY[index][j]);
				queue_add(que,str);
			}
		}
	}
	queue_prt_str(que);
	
	*returnSize = que->size;
	return &(que->array[que->head]);
}
int main()
{
	char *str = "23";
	int size=0; 
	char **p = letterCombinations(str,&size);
	for(int i=0;i<size;i++){
		printf("%s\t",p[i]);
	}
	
}
