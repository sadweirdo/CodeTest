#include"../macro.h"
/* ֻ���޸�����ǰ��Ԫ��ʹ�������ȼ��ɣ����� 0 0 0 ��������Ͳ����޸�ֱ�ӷ��� */ 
int removeDuplicates(int* nums, int numsSize)
{
    if(numsSize ==0 ) return 0;
    int i,j;
	for(i=0,j=0;j<numsSize;j++)
		if(nums[j]!=nums[i])	nums[++i]= nums[j];
	return i+1;
}
