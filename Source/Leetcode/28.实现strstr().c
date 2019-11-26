#include<stdio.h>
#include<stdlib.h>
#include"../macro.h"
#include"../string.h"

int violen_searchstr(char *srcstr, int srccnt, char *tarstr, int tarcnt)
{
    for(int i=0, j ;i<=srccnt-tarcnt ;i++){
        for(j=0 ;j<tarcnt ;j++){
            if(srcstr[i+j]!=tarstr[j])	break;
        }
		if(j == tarcnt)		return i;
    }
    return -1;
}
int strStr(char * haystack, char * needle)
{
    int ncnt = str_len(needle);
    if(!ncnt) return 0;
    int hcnt = str_len(haystack);
    if(hcnt < ncnt)  return -1;
    
    return violen_searchstr(haystack,hcnt,needle,ncnt);
}