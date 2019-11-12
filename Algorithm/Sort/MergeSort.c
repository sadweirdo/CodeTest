#include"list.h"

/* MERGESORT*/ 
void merge(int *num,int low,int mid,int high,int *tmp)
{
	prpara(low:[%d]\tmid:[%d]\thigh:[%d],low,mid,high);
	if(mid>=high) return;
	int i,size = high-low+1;
	
	int j=low,k=mid+1;
	for(i=0;i<size;i++){
		if(j==mid+1&&k<=high)	tmp[i]=num[k++];
		else if(k==high+1&&j<=mid) tmp[i]=num[j++];
		else if(num[j]<=num[k])	tmp[i]=num[j++];
		else tmp[i]=num[k++];
	}
	for(i=0;i<size;i++)
		num[low+i]=tmp[i];
	
	prarray(num+low,size);
	pr(\n);
}

void mergesort_td(int *num,int low,int high,int *tmp)
{

	prpara(low:[%d]\thigh:[%d]\tnumbers:[%d],low,high,high-low+1);
	prarray(num+low,high-low+1);
	pr(\n);
	
	if(low>=high)	return;
	int mid = (low+high)/2;
	mergesort_td(num,low,mid,tmp);
	mergesort_td(num,mid+1,high,tmp);

	merge(num,low,mid,high,tmp); 
}

void mergesort_dt(int *num,int low,int high,int *tmp)
{
	prpara(num:[%d],high-low+1);
	int size = high-low+1;
	int count,i=2;
	int index=2;
	int mid,hi;
	
	for(count=1;(size>=i*2)||(size>i&&size<i<<1);	\
		i*=2,count++,pr(i:[%d] count:[%d]\n,i,count));
	
	for(i=0;i<count;i++){
		for(int j=0;j<high;){
			hi = j+index-1>high?high:j+index-1;
			mid = (j*2+index-1)/2;
			pr(low:[%d] mid:[%d] high:[%d]\n,j,mid,hi);
			merge(num,j,mid,hi,tmp);
			j+=index;
		}
		index<<=1;
	}
}

/* QUICKSORT */
void quicksort(int *num,int low,int high)
{
	if(low>=high) return;
	
	prpara(low:[%d]\thigh:[%d]\tnumbers:[%d]\t,low,high,high-low+1);	
	prarray(num+low,high-low+1);
	pr(\n);
	
	int *nums = num+low;
	int i=0,j=high-low;
	int king=nums[low];
	
	while(i<j){
		while(nums[j]>king&&i<j)	j--;
		nums[i]=nums[j];
		
		while(nums[i]<king&&i<j)	i++;
		nums[j]=nums[i];
	}
	pr(i:[%d]\t,i);
	prarray(num+low,high-low+1);
	pr(\n);
	
	if(i==j)
		nums[j]=king;
	else{
		pr(SORT ERROR);
		return;	
	}
	quicksort(num,low,low+i-1);
	quicksort(num,low+i+1,high);
}
int main()
{
	int test[100]={185,23,6,8,39,4,142,423,65,48,6186,1531,565,1234,231,848,68,651,321,848,135,9,98,497,48949,616,84651,8461,848,16468,484,164};
	int count;
	for(count=0;test[count];count++);//2
	int *tmp;
	mll(tmp,count-1);
	quicksort(test,0,count-1);
	printarray(test,count);
	
}

