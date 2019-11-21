#include<stdio.h>
#include<stdlib.h>
#include"../macro.h"
#include"../string.h"

int romanToInt(char * s)
{
    int roman[128]={0};
    int index = str_len(s);
    int sum=0,flag=1;
    roman['I']=1;roman['V']=5;roman['X']=10;roman['L']=50;
	roman['C']=100;roman['D']=500;roman['M']=1000;
    
    for(int i=0,tmpp=0,tmpn;i<index;i++){
        tmpn = roman[s[i]];
        flag = tmpn > tmpp? -1 : 1;
        sum += flag * tmpp;
        tmpp = tmpn;
    }    
    sum += roman[s[index-1]];
    return sum;
}