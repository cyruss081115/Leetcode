#include <stdio.h>
#include <stdlib.h>

/* 
 * This a two pointer approach of merging.
 * Both pointers move from tail to head
 */

void swap(int* num1, int* num2) {
    int tmp = *num1;
    *num1 = *num2;
    *num2 = tmp;
}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    // Start from the last position of each array
    int i = m - 1;
    int j = nums2Size - 1;
    int toBeMerged = nums1Size - 1;
    
    // Put the maximum of 2 unprocessed array into pos to be merged
    while (i >= 0 && j >= 0) {
        if (nums1[i] <= nums2[j]) {
            nums1[toBeMerged--] = nums2[j--];
        } else if (nums1[i] > nums2[j]) {
            swap(&(nums1[toBeMerged--]), &(nums1[i--]));
        }
    }
    
    // Fill the remaining entries from nums2 if there still are
    while (j >= 0) {
            nums1[toBeMerged--] = nums2[j--];
    }
}

int main() {
    int arr1[] = {1,2,3,0,0,0};
    int size1 = 6;
    int arr2[] = {2,5,6};
    int size2 = 3;
    merge(arr1, size1, 3, arr2, size2, 3);
    for (int i = 0; i < size1; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");
}