//
// Created by jiangecho on 16/7/8.
//
#include <stdlib.h>
#include "344.h"

char *reverseString(char *s) {
    if (s == NULL) {
        return NULL;
    }

    char *p_start;
    char *p_end;
    p_start = p_end = s;
    while (*p_end != '\0') {
        p_end++;
    }

    int length = p_end - p_start;
    p_start = (char *) malloc(length + 1);

    for (int i = 0; i < length; ++i) {
        *(p_start + i) = *(s + length - 1 - i);
    }
    *(p_start + length) = '\0';

    return p_start;
}