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

/*		KMP搜索		*/
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

/*		KMP算法接口函数	*/
int kmp_searchstr(char *src, int srccnt, char *tar, int tarcnt)
{
	if(tarcnt == 0)	return 0;
	if(tarcnt > srccnt)	return -1;
	int *next = _kmp_createnext(tar,tarcnt);
	if(!next){
		printf("Error: next array create failed!\n");
		return -1;
	}
    for(int j=0;j<tarcnt;j++)
        printf("%d ",next[j]);
	return _kmp_search(src,srccnt,tar,tarcnt,next);
}