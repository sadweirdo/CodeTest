#include<stdio.h>
#include<stdlib.h>
#include"../macro.h"
#include"../string.h"

/* 竖排扫描 */
char * longestCommonPrefix1(char ** strs, int strsSize)
{
	int len = 0;
	
	if(strsSize == 0)  return "";
	
	for(char tmpo,tmp ;strs[0][len] ;len++){
		tmpo = strs[0][len];
		for(int i=0 ;i<strsSize ;i++){
			tmp = strs[i][len];
			if(tmp == '\0' || tmp != tmpo)
				goto OUT;
		}
	}
	
	char *str
OUT:
	str = mlloc(char,len+1);
	mem_cpy(str,strs[0],len);
	str[len]='\0';
	
	return str;
}





/* 归并 */
char * merge(char *a,char *b)
{
    if(!a || !b)    return NULL;
    
	int len;
    
	for(  ;  ;len++){
		if(a[len]=='\0' || a[len]!=b[len])
			break;
    }
	char *str = mlloc(char,len+1);
	mem_cpy(str,a,len);
	str[len]='\0';
    
	return str;
}
char * mergecommon(char **str,int low, int high)
{
	char *string;
	if(low > high)	return NULL;
	if(low == high){					//保证left和right都是函数内部malloc分配的内存，可以释放
		string = mlloc(char,str_len(str[low])+1);
		mem_cpy(string,str[low],str_len(str[low])+1);
		return string;
	}		
	if(high == low+1)	return merge(str[low],str[high]); //这里并非再为了保证malloc，而是为了避免
																		//下方再次递归的开销(包括lowhigh变量相等重新malloc)
	char *left,*right;		
	int mid = (low+high)/2;
	left = mergecommon(str,low,mid);	//递归执行到此可以保证变量指向的是新malloc分配的而非str递归参数
	right = mergecommon(str,mid+1,high);
	
	string = merge(left,right);
	free(left); free(right);
	return string;
}
char * longestCommonPrefix(char ** strs, int strsSize)
{
	if(strsSize==0) return "";
	return mergecommon(strs,0,strsSize-1);
}





/* 二分查找法 */
int isprefix(char **strs,int size,int len)
{
    for(int j=0;j<=len;j++){
        for(int i=1;i<size;i++){
            printf("%c-%c ",strs[0][j],strs[i][j]);
            if(strs[0][j] != strs[i][j])
                return 0;
        }
    }
    return 1;
}
char * longestCommonPrefix(char ** strs, int strsSize)
{
    if(strsSize == 0)   return "";
    
    int min = str_len(*strs);
    for(int i=1,tmp;i<strsSize;i++){
        tmp = str_len(strs[i]);
        min = tmp<min?tmp:min;
    }
    int low = 0 ,high = min-1>0?min-1:0 ,mid;
    while(low < high){
        mid = (low + high)/2;
        if(isprefix(strs,strsSize,mid)){
            low = mid+1;
        }else{
            high = mid;
        }
    }
    int num = isprefix(strs,strsSize,low)? low+1:low;
    char *s = (char *)malloc(num+1);
    mem_cpy(s,*strs,num);
    s[num]='\0';
    return s;
}