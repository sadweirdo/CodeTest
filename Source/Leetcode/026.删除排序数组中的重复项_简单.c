#include"../macro.h"
/* ֻ���޸�����ǰ��Ԫ��ʹ�������ȼ��ɣ����� 0 0 0 ��������Ͳ����޸�ֱ�ӷ��� */ 
int removeDuplicates(int* nums, int numsSize)
{
    if(!numsSize)   return 0;
    
    int index=0;
    for(int i=1;i<numsSize;i++){
        if(nums[i]!=nums[index])
            nums[++index] = nums[i];
    }
    return index+1;
}
/* ��������� */
int removeDuplicates(int* nums, int numsSize)
{
    if(!numsSize)   return 0;
    
    int index=0;//���������prev = nums[index]
    int count = 1;
    for(int i=1;i<numsSize;i++){
        if(nums[i]!=nums[index])   continue;
        nums[++index] = nums[i];
        count++;
    }
    return count;
}