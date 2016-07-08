//
// Created by jiangecho on 16/7/8.
//
#include "258.h"

int addDigitsR(int num) {
    if (num >= 10) {
        return num % 10 + addDigitsR(num / 10);
    } else {
        return num % 10;
    }
}

int addDigits(int num) {
    int result = addDigitsR(num);
    int tmp = 0;
    if (result >= 10) {
        tmp = addDigits(result);
    } else {
        tmp = result;
    }
    return tmp;
}

