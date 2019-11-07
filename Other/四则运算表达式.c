#include"../macro.h"
#define TYPEC int
#include"../array.h"

#define MAX_SIZE 200

double calc(char *str)
{
	char prio[128]={0};
		prio['+']=prio['-']=1;
		prio['*']=2;
		prio['/']=3;
		
	Stack *num,*sym;
	num = stack_init(MAX_SIZE);
	sum = stack_init(MAX_SZIE);
	
	
	return 0;
}


int main()
{
	char *str;
	str = mlloc(char,MAX_SIZE);
	scanf("%s",str);
	prts(str);
	double ret = calc(str);
	prt("Val:%d",ret);
} 

