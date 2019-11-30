#include<stdio.h>
#include<stdlib.h>
#include"../macro.h"
#include"../string.h"
char * addBinary(char * a, char * b)
{
	int lena = str_len(a);
	int lenb = str_len(b);
	int lentmp;
	char *strtmp;
	if(lenb > lena){
		exchange(lena,lenb,lentmp);
		exchange(a,b,strtmp);
	}
	char s[lena+1];
	int cnt=0,carry=0,x,y;
	for(int i=0;i<lenb;i++){
		x = a[lena-1-i]-'0'; y = b[lenb-1-i]-'0';
		s[cnt++] = x^y^carry + '0';
		carry = (x+y+carry)>>1;
	}
	for(int i=lenb;i<lena;i++){
		x = a[lena-1-i]-'0';
		s[cnt++] = x^carry+'0';
		carry = (x+carry)>>1;
	}
	if(carry)	s[cnt++]='1';
	char *re = (char*) malloc (sizeof(char)*cnt+1);
    for(lentmp=0; cnt>0 ;)
         re[lentmp++] = s[--cnt];
    re[lentmp] = '\0';
    return re;
}