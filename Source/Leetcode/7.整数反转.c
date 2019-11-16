#include"../macro.h"

/* 假设环境仅能存储32位有符号整数 */

	
int reverse(int x){
	char *str;
	int count;
	count = numtostring(x ,&str);
	if(count) prt(Error:transfer to string fail);
	prts(str);
	
	for(char i=0,tmp;i<count/2;i++)
		exchange(str[i] ,str[count-1-i] ,tmp)
	prts(str);
	
	return stringtonum(str);
}