//
// Created by jiangecho on 16/7/16.
//
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool isPair(char left, char right) {
    bool result = false;
    switch (right) {
        case ')':
            result = left == '(';
            break;
        case ']':
            result = left == '[';
            break;
        case '}':
            result = left == '{';
            break;
        default:
            break;
    }
    return result;
}

bool isValid(char *s) {
    if (s == NULL) {
        return false;
    }
    int len = 0;
    char *p = s;
    while (*p != '\0') {
        len++;
        p++;
    }

    p = (char *) malloc(len + 1);
    memset(p, '\0', len);
    char *bottom = p;

    while (*s != '\0') {
        if (bottom == p) {
            *p = *s;
            p++;
        } else {
            if (!isPair(*(p - 1), *s)) {
                *p = *s;
                p++;
            } else {
                p --;
            }
        }
        s++;
    }

    return p == bottom;
}



