#include<stdio.h>
#include<stdlib.h>
long long reverse(long long num,long long ret)
{
    return num==0?ret:reverse(num/10,ret*10+num%10);
}
int isPalindrome1(int x)
{
    long long num = x;
    if(x<0) return 0;
    long long palin = reverse(num,0);
    if(num == (int)palin)     return 1;
    else return 0;
}

/* 32位解法 */
int isPalindrome(int x)
{
	int num=0;

	if(x<0 || x%10==0 && x!=0  ) return 0;
	for(; num < x; x/=10)
		num = num*10 + x%10;
	
	return num == x || num/10 == x;
}
int main()
{
    int c;
    while(scanf("%d",&c)){
        printf("%d\n",isPalindrome(c));
    }
 } 
