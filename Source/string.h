/* 依赖macro.h */
static char *INT_MIN_STRING = "2147483648";
static char *INT_MAX_STRING = "2147483647";

/*  1-str1>str2  0-str1=str2  -1-str1<str2 */
static inline int str_cmp(char *str1,char *str2)
{
    if(str1 == NULL && str2 == NULL)
        return 0;
    else if(str1 == NULL)
        return (int)(-(*str2));
    else if(str2 == NULL)
        return (int)(*str1);
	while(*str1 != '\0' && *str2 != '\0' && *str1 == *str2){
		str1++; str2++;
	}
	return (int)(*str1 - *str2);
}

static inline int str_len(char *string)
{
	int i;
	for(i=0 ;string[i] ;i++);
	return i;
}
static inline int mem_cpy(char *dst ,char *str ,int count)
{
	if(!dst || !str) return 0;
	int num = str_len(str);
	num = min(num,count);
	for(int i=0 ;i<num ;i++)
		dst[i] = str[i];
	
	return num;
}
/* 数字字符串比较 */
int numstr_cmp(char *str1,char *str2)
{
    for(;*str1 == '0';str1++);	//消除0开头字符
    for(;*str2 == '0';str2++);
    
    int cnt1 = str_len(str1);
    int cnt2 = str_len(str2);
    
    if(cnt1 > cnt2)    return 1;
    else if(cnt1 < cnt2)    return -1;
    
    return str_cmp(str1,str2);//位数一样则进行字符串比较
}

/* 32位有符号十进制数值转化为字符串 */
/* flag:0-positive 1-negative */
int dec_to_str(int x,int *flag,char **string)
{
	int num = x ;
	int count= num_decdigits(x);
	
	*flag = x>=0?0:1;
	*string = mlloc(char,count+1);
	if(!*string) return 0;
	
	if( x==INT_MAX)
		for(int i=0;i<count;i++) (*string)[i]=INT_MAX_STRING[i];
	else if(x == INT_MIN)	//若x=INT_MIN，则x无法用下文中num=-x变为正数，因此这里必须单独列举
		for(int i=0;i<count;i++) (*string)[i]=INT_MIN_STRING[i];
	else{
		if(x<0)	num = -x;	//将x化为正数进行处理，避免不同编程语言负数取余的区别
		for(int i=count-1,tmp ;i>=0 ;i--){
			tmp = num%10;
			num/=10;
			(*string)[i] = tmp + '0';
		}
	}
	(*string)[count]='\0';
	
	return count;
}

/* 字符串化为32位有符号正数 */
/* flag:0-positive 1-negative */
int str_to_dec(char *string,int flag)
{
    int ret = 0;
    
	char *cmp = flag?INT_MIN_STRING:INT_MAX_STRING;
	if(numstr_cmp(string,cmp) >0)	//若字符串化为整数出现int溢出，则返回0
	   return 0;
	
	int index = str_len(string);
    for(int i=0 ;i<index ;i++)
		ret = ret*10 + string[i]-'0';
		
	return flag?-ret:ret;
}

/*		暴力法搜索字符串		*/
int violen_searchstr(char *srcstr, int srccnt, char *tarstr, int tarcnt)
{
	if(tarcnt == 0)	return 0;
	if(tarcnt > srccnt)	return -1;
    for(int i=0, j ;i<=srccnt-tarcnt ;i++){
        for(j=0 ;j<tarcnt ;j++){
            if(srcstr[i+j]!=tarstr[j])	break;
        }
		if(j == tarcnt)		return i;
    }
    return -1;
}
/*		暴力法一层循环实现		*/
int violen_searchstr(char *srcstr, int srccnt, char *tarstr, int tarcnt)
{
    int i=0, j=0;
    for( ;i<=srccnt-tarcnt && j<tarcnt;){
        if(srcstr[i+j]!=tarstr[j]){
            i++;j=0;
        }
        else
            j++;
    }
    if(j == tarcnt)		return i;
    return -1;
}

/*	KMP算法	*/
/*		创建next数组，索引0开始		*/
static inline int *_kmp_createnext(char *tar, int tarcnt)
{
	int *next = calloc(tarcnt,sizeof(int));
	if(tarcnt == 1) return next;
	int i = 1;		//i代表后子串中最后一个待匹配的字符，同时是字符串遍历索引
	int k = 0;		//k代表前子串中最后一个待匹配的字符
	
	/*	next[0]=next[1]=0，因为calloc申请所以没有省略赋值 */
	while(i<tarcnt-1){
		if(tar[i] == tar[k])
			next[++i] = ++k;	//next数组索引是不匹配字符位置，因此要++i。
											//next值是待匹配字符位置，因此要++k。
		else if(k==0)   next[++i]=0; 	//排除下面这种情况可能会出现的无限循环
        else
			k = next[k];
	}
	return next;
}

static inline int _kmp_search(char *src, int srccnt, char *tar, int tarcnt, int *next)
{
	int i,j;
	for(i=0, j=0  ;i<srccnt && j<tarcnt;){
		 if(src[i]==tar[j]){
			 i++;j++;
		 }
		 else if(j==0)	i++; 	//排除下面这种情况可能会出现的无限循环
		 else
				j=next[j];
	}
	if(j == tarcnt)		return i-j;
	else return -1;
}
int kmp_searchstr(char *src, int srccnt, char *tar, int tarcnt)
{
	if(tarcnt == 0)	return 0;
	if(tarcnt > srccnt)	return -1;
	int *next = _kmp_createnext(tar,tarcnt);
	if(!next){
		printf("Error: next array create failed!\n");
		return -1;
	}
	return _kmp_search(src,srccnt,tar,tarcnt,next);
}
