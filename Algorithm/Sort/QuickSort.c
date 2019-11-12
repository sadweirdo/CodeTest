#include"../macro.h"
#include<string.h>
void quicksort(int *num,int low,int high)
{
	if(low >= high) return;
	
	REFI	int i=low , j=high;
	REFO	int val = num[low];

	while(i<j){
		while(i<j && num[j]>=val)	j--;
		num[i]=num[j];
		while(i<j && num[i]<=val)	i++;
		num[j]=num[i];
	}

	num[i]=val;
	
	quicksort(num,low,i-1);
	quicksort(num,i+1,high);
 } 
 
 int main()
 {
 	int a[]={45,1,2,4,5,6,23,7,834,12,4};
 	int size = sizeof(a)/4;
 	quicksort(a,0,size-1);
 	for(int i=0;i<size;i++)
 		prt(%d\t,a[i]);
 }
