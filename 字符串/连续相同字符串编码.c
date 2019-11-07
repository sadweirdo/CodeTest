#include"../macro.h"
#include<string.h>
#define EQUALNUM 10 
struct code{
	int subnum;	//减少的字符数量 
	int num;	//字符串连续相同的数量，数组表示会有多个连续相同字串 
	int sublen;
	int index;	//字符串索引 
};
char * codeformat(char *str)
{
	REFI	int len = strlen(str);
	REFI	int sublen = len/2;	//相同子字串长度，从大到小处理 
	OUT		char* string;
	REFO	struct code allcode={0,0,0,0},tmpcode={0,1,0,0};
	
	PARAMACCESS_START
	if(!str)	return NULL;
	if(len <=4)	return str;
	PARAMACCESS_END
	
	for(;sublen>0;sublen--) {
		for(int j=0;j<=len-2*sublen;j++){
			if(tmpcode.subnum){
				memset(&tmpcode,0,sizeof(struct code));
				tmpcode.num=1;
			}
			for(int k=j;k<=len-2*sublen && !strncmp(str+k,str+k+sublen,sublen);k+=sublen){
				tmpcode.sublen = sublen;
				tmpcode.subnum+=sublen;
				tmpcode.index = j;
				tmpcode.num++; 
			}
			if(tmpcode.subnum>3&&tmpcode.subnum>allcode.subnum){
				memcpy(&allcode,&tmpcode,sizeof(struct code));
			}
		}
	}
	
	prtd4(allcode.subnum,allcode.sublen,allcode.index,allcode.num);
	if(!allcode.subnum)	return str;
	int size = len+1-allcode.subnum+2;
	int indexnew=0,indexold=0;
	char tmpstr[4]={0};
	sprintf(tmpstr,"%d",allcode.num);
	int numbytes =strlen(tmpstr);
	
	string = mlloc(char,size+numbytes);
	memcpy(string,str,allcode.index);
	indexnew+=allcode.index;
	indexold+=allcode.index;
	memcpy(string+indexnew,tmpstr,numbytes);
	indexnew+=numbytes;
	string[indexnew++]='[';
	memcpy(string+indexnew,str+indexold,allcode.sublen);
	indexnew+=allcode.sublen;
	indexold+=allcode.num*allcode.sublen;
	string[indexnew++]=']';
	size = len - allcode.index - allcode.num*allcode.sublen;
	memcpy(string+indexnew,str+indexold,size);
	indexnew+=size;
	string[indexnew]='\0';
	prts(string);
	return codeformat(string);
} 
int main()
{
	char *str = "aaa";
	char *p = codeformat(str);
	prts(p);
}
