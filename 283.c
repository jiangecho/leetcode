#include <stdio.h>

void moveZeroes(int *nums, int numsSize) {
    int count = 0;
    for (int i = 0; i < numsSize;) {
        if (nums[i] == 0 && (i != (numsSize - 1))) {
            for (int j = i; j < numsSize; j++) {
                nums[j] = nums[j + 1];
            }
            nums[numsSize - 1] = 0;
            if (nums[i] != 0) {
                i++;
            }
            count ++;

            if(count >= numsSize){
                break;
            }
        } else {
            i++;
        }

    }
}

//int main(int argc, const char *argv[]) {
//    int test[] = {0, 1, 0, 3, 12};
//    printf("hello world abcc\n");
//    moveZeroes(test, sizeof(test) / sizeof(int));
//    for (int i = 0; i < sizeof(test) / sizeof(int); i++) {
//        printf("%d", test[i]);
//    }
//}
