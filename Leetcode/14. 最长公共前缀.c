#include"../macro.h"
#include<memory.h>
#define true 1 
char * longestCommonPrefix1(char ** strs, int strsSize)
{
	int len=0;
	char *str=NULL;
	
	if(strsSize==0)  return "";
	while(true){
		int rc=0;
		char common=strs[0][len],tmp=0;

		for(int i=0;i<strsSize;i++){
			tmp = strs[i][len];
			if(tmp=='\0' || tmp!=common){
				rc=1;
				break;
			}
		}
		if(rc)	break;
		len++;
	}

	str = mlloc(char,len+1);
	memcpy(str,strs[0],len);
	str[len]='\0';
	
	return str;
}

char * merge(char *a,char *b)
{
	char *str=NULL;
	int i=0;
	for(i=0;;i++){
		if(a[i]!=b[i] || a[i]=='\0')
			break;
	}
	str = mlloc(char,i+1);
	memcpy(str,a,i);
	str[i]='\0';
    
	return str;
}
char * mergecommon(char **str,int low, int high)
{
	if(low > high)	return NULL;
	if(low == high)	return str[low];
	if(high == low+1)	return merge(str[low],str[high]);
	
	int mid = (low+high)/2;
	char *left,*right;
	left = mergecommon(str,low,mid);
	right = mergecommon(str,mid+1,high);

	return merge(left,right);
}
char * longestCommonPrefix2(char ** strs, int strsSize)
{
	if(strsSize==0) return "";
	return mergecommon(strs,0,strsSize-1);
}

int main()
{
	char * strs[] = {"leets","leetcode","leetside","lees","let"};
	char *str = longestCommonPrefix2(strs,5);
	prt(%s\n,str);
}
