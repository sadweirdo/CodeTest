#include<stdio.h>
#include<stdlib.h>
#include"../macro.h"
#include"../string.h"


int strStr(char * haystack, char * needle)
{
    return violen_searchstr(haystack,str_len(haystack),needle,str_len(needle));
}