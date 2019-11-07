#include"../macro.h" 
double findMedianSortedArrays_merge(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int *num = (int *)malloc((nums1Size+nums2Size)*sizeof(int));
    int i=0,j=0,k=0;
    int index;
    double number;
    while(i<nums1Size&&j<nums2Size){
        if(nums1[i]<nums2[j])
            num[k++]=nums1[i++];
        else
            num[k++]=nums2[j++];
    }
    while(i<nums1Size)
        num[k++]=nums1[i++];
    while(j<nums2Size)
        num[k++]=nums2[j++];
    
    index = (nums1Size+nums2Size)/2;
    if((nums1Size+nums2Size)%2)
        number = num[index];
    else
        number = (num[index]+num[index-1])/2.0;
    return number;
}
