#include<stdio.h>
#include<stdlib.h>
#include"../macro.h"
#include"../string.h" 
/* 假设环境仅能存储32位有符号整数 */

/* 字符串转化 */
int reverse(int x)
{
	char *str;
	int count;
    int num = x,flag;
    
	count = dec_to_str(num ,&flag ,&str);
	if(!count) prt(Error:transfer to string fail);
	for(char i=0,tmp;i<count/2;i++)
		exchange(str[i] ,str[count-1-i] ,tmp)
	return str_to_dec(str,flag);
}

/* 直接判断溢出 */
int reverse(int x)
{
    int rev = 0;
    while (x != 0) {
        int pop = x % 10;	//不同编程语言负数取余规则不同会导致结果错误
        x /= 10;
        if (rev > INT_MAX/10 || rev < INT_MIN/10) return 0;
        rev = rev * 10 + pop;
    }
    return rev;
}
