#include<stdio.h>
#include<stdlib.h>

#define IN
#define REFI
#define OUT
#define REFO
#define DATAS 
#define PARAMACCESS_START
#define PARAMACCESS_END

#define prt(args,...)	(printf(#args,##__VA_ARGS__))
#define prtd(a)			(printf(#a":[%d]\n",a))
#define prtd2(a,b)		(printf(#a":[%d]\t"#b":[%d]\n",a,b))
#define prtd3(a,b,c)	(printf(#a":[%d]\t"#b":[%d]\t"#c":[%d]\n",a,b,c))
#define prtd4(a,b,c,d)	(printf(#a":[%d]\t"#b":[%d]\t"#c":[%d]\t"#d":[%d]\n",a,b,c,d))
#define prts(a)			(printf(#a":[%s]\n",a))
#define PLINE	(printf("\n"))

#define mloc(type) ((type *)malloc(sizeof(type)))
#define mlloc(type,n) ((type *)malloc(sizeof(type)*(n)))
#define clloc(type,n) ((type *)calloc((n),sizeof(type)))

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)>(b)?(b):(a))

#define exchange(a,b,tmp)	{(tmp)=(a); (a)=(b); (b)=(tmp);}
