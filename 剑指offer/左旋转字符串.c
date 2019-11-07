#include"../macro.h" 
#include<string.h>
void rotatestring(char *str,int size)
{
	int i=0,j=size-1;
	char tmp;
	while(i<j){
		exchange(str[i],str[j],tmp);
		i++;j--;
	}
 } 
 
char* leftRotateString(char* str, int n){
    
    int len = strlen(str);
    if(len == 0||len==1)    return str;
    n%=len;
	rotatestring(str,n);
	rotatestring(str+n,len-n);
	rotatestring(str,len);
	
	return str;
}

