void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int i = nums1Size-1-nums2Size;
    int j = nums2Size-1;
    int index=nums1Size-1;
        
    for(;index>=0 && i>=0 && j>=0;index--){
        if(nums2[j]>=nums1[i])  nums1[index] = nums2[j--];
        else nums1[index] = nums1[i--];
    }
    for(;j>=0;j--)
        nums1[index--]=nums2[j];
}