#include"../macro.h"
#include<memory.h>

#include"../macro.h"
#define MAX 1500 //求MAX范围内的素数
long long su[MAX],cnt;
char isprime[MAX+1];
char primecount[MAX+1]={0}; 
void prime()
{
    cnt=1;
    memset(isprime,1,sizeof(isprime));//初始化认为所有数都为素数
    isprime[0]=isprime[1]=0;//0和1不是素数
    for(long long i=2;i<=MAX;i++)
    {
        if(isprime[i])
            su[cnt++]=i;//保存素数i
            
        /*for(long long j=i*2;j<=MAX;j+=i)//素数的倍数都为合数
        {
            isprime[j]=0;
            primecount[j]++;
		}*/
		
        for(long long j=1;j<cnt&&su[j]*i<MAX;j++)
        {
            isprime[su[j]*i]=0;//筛掉小于等于i的素数和i的积构成的合数
            primecount[su[j]*i]++;
        }
    }
    int max=0,sum=0;
    for(long long i=1;i<=MAX;i++){
    	sum+=primecount[i];
		printf("%d ",primecount[i]);
		max = max(max,primecount[i]);
	}
	PLINE;prt(sum:%d\tmax:%d\n,sum,max);
    	
}

int * findprime(int numsize)
{
	char state[numsize+1];
	int *prime=mlloc(int,numsize);
	memset(prime,0,sizeof(int)*numsize);
	int count=0;
	for(int i=0;i<=numsize;i++)	state[i]=1;
	
	for(int i=2;i<=numsize;i++){
		if(state[i]){
			prime[count++]=i;	
			for(int j=i*i;j<=numsize;){
				state[j]=0;
				//prt(j:%d\n,j);
				for(j++;j<=numsize;j++)
					if(state[j]){
						j *=i;
						break;	
				}
			}
			prt(i=%d\t--1--2--3--4--5--6--7--8--9--10\n,i);
			int line = numsize%10?numsize/10+1:numsize/10;
			int cow = numsize%10;
			for(int k=0;k<line;k++){
				prt(%d-%d:\t,k*10+1,k*10+10);
				for(int l=0;l<cow;l++)
					prt(_ %d,state[k*10+l+1]); 
				PLINE;
			}
			PLINE;PLINE;
		}
			
	}
	return prime;
}
int main()
{
	int *ret = findprime(8);
	int i=0;
	while(ret[i]){
		prt(%d\t,ret[i++]);
	}
	prt(\ncount:[%d],i);
 } 
