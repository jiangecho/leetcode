//
// Created by jiangecho on 16/7/8.
//
#include <stdlib.h>
#include <stdio.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int *nums, int numsSize, int target) {
    int *p = (int *) malloc(sizeof(int) * 2);

    for (int i = 0; i < numsSize; ++i) {
        for (int j = i + 1; j < numsSize; ++j) {
            if (nums[i] + nums[j] == target) {
                p[0] = i;
                p[1] = j;
            }

        }
    }

    return p;

}

