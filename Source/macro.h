
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
#define max3{a,b,c) (max(max(a,b),c))
#define min3{a,b,c) (min(min(a,b),c))

#define exchange(a,b,tmp)	{(tmp)=(a); (a)=(b); (b)=(tmp);}

#define num_decdigits(x) (numdigits(x,1))
#define num_hexdigits(x) (numdigits(x,2))

/* scalegflag: 1-decimal    2-hexadecimal */
static inline int numdigits(long long num, char scaleflag)
{
	int count = 1;
	int scale;
	switch(scaleflag){
		case 1:
			scale = 10;
			break;
		case 2:
			scale = 16;
			break;
		default:
			prt("Error: invalid scaleflag input");
			return 0;
	}
	
	for(int tmp=num ;tmp/=scale ;count++);
	return count;
}
