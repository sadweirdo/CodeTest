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
    
    return str_cmp(str1,str2);
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

