#include <stdio.h>
#include <stdlib.h>

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    // Put the array input with smaller size into the hashtable
    // The hashtable will store the freq of appearance of the key
    int Table[1001] = {0};
    int minArr = nums1Size < nums2Size ? 1 : 0;
    int* ret; *returnSize = 0;
    if (minArr) {
        ret = (int*)malloc(sizeof(int) * nums1Size);
        for (int i = 0; i < nums1Size; i++) {
            // Recording freq
            Table[nums1[i]] += 1;
        }  

        // For every element, if it exist in the hashtable, i.e. freq > 0
        // freq--, append return array with current input
        for (int i = 0; i < nums2Size; i++) {
            if (Table[nums2[i]] > 0) {
                ret[(*returnSize)++] = nums2[i];
                Table[nums2[i]]--;
            }
        }
    } else {
        ret = (int*)malloc(sizeof(int) * nums2Size);
        for (int i = 0; i < nums2Size; i++) {
            Table[nums2[i]] += 1;
        }

        for (int i = 0; i < nums1Size; i++) {
            if (Table[nums1[i]] > 0) {
                ret[(*returnSize)++] = nums1[i];
                Table[nums1[i]]--;
            }
        }
    }    
    return ret;
    
}

int main() {
    int nums1[] = {1, 2, 2, 1}; int size1 = 4;
    int nums2[] = {2, 2}; int size2 = 2;
    int returnSize = 0;
    int* ret = intersect(nums1, size1, nums2, size2, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", ret[i]);
    }
    printf("\n");
}