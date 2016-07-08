//
// Created by jiangecho on 16/7/8.
//

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include "349.h"
#include <stdlib.h>
#include <string.h>

int contain(int *nums, int size, int num) {
    for (int i = 0; i < size; ++i) {
        if (nums[i] == num) {
            return 1;
        }
    }

    return 0;
}

int *intersection(int *nums1, int nums1Size, int *nums2, int nums2Size, int *returnSize) {
    int maxSize = nums1Size < nums2Size ? nums1Size : nums2Size;
    int *p = (int *) malloc(maxSize * sizeof(int));
    memset(p, 0, maxSize);

    int *cur = p;
    for (int i = 0; i < nums1Size; ++i) {
        for (int j = 0; j < nums2Size; ++j) {
            if (nums1[i] == nums2[j] && contain(p, cur - p, nums1[i]) == 0) {
                *cur = nums1[i];
                cur++;
            }

        }
    }

    *returnSize = cur - p;
    return p;

}