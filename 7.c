//
// Created by jiangecho on 16/7/9.
//
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

int reverse(int x) {
    //long tmp = x > (int)0 ? x : -x;
    long tmp = (long) x > 0 ? (long) x : -(long) x;
    long result = 0;

    while (true) {
        result = result * 10 + tmp % 10;
        if (tmp / 10 > 0) {
            tmp /= 10;
        } else {
            break;
        }
    }

    result = x > 0 ? result : -result;

    // overflow
    if (result > INT32_MAX || result < INT32_MIN) {
        return 0;
    }

    return result;


}

int test_7() {
    int test = -2147483648;
    int result = reverse(test);

}

