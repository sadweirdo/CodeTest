#include<stdio.h>
#include<stdlib.h>
#include"../macro.h"
#include"../string.h"

char s[30][4500]={"1",0};
char * countAndSay(int n){
    for(int i=1;i<n;i++)
        for(int len = strlen(s[i-1]), index=0, count=1, tmp=s[i-1][0], j=1;j<=len;j++)
            if( j!=len && tmp == s[i-1][j])    count++;
            else{
                s[i][index++] = count+'0';
                s[i][index++] = tmp;
                count = 1;
                tmp = s[i-1][j];
            }
    return s[n-1];
}