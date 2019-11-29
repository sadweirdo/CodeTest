#include<stdio.h>
#include<stdlib.h>
#include"../macro.h"
#include"../string.h"
int lengthOfLastWord(char * s)
{
    int len = str_len(s);
    for(;len>=1&&s[len-1]==' ';len--);
    for(int i=len-1;i>=0;i--){
        if(s[i]==' ')   return len-1-i;
    }
    return len;
}