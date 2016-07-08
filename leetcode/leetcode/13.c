//
//  13.c
//  leetcode
//
//  Created by jiangecho on 16/7/7.
//  Copyright © 2016年 jiangecho. All rights reserved.
//

#include "13.h"


int romanCharToInt(char c){
    int value;
    switch(c){
        case 'I':
            value = 1;
            break;
        case 'V':
            value = 5;
            break;
        case 'X':
            value = 10;
            break;
        case 'L':
            value = 50;
            break;
        case 'C':
            value = 100;
            break;
        case 'D':
            value = 500;
            break;
        case 'M':
            value = 1000;
            break;
        default:
            break;
    }
    
    return value;
}

int romanToInt(char* s) {
    char* p = s;
    int result = 0;
    while(*p != '\0'){
        if(*(p + 1) == '\n'){
            result += romanCharToInt(*p);
            break;
        }
        if(romanCharToInt(*p) >= romanCharToInt(*(p + 1))){
            result += romanCharToInt(*p);
            p ++;
        }else{
            result += romanCharToInt(*(p + 1)) - romanCharToInt(*p);
            p += 2;
        }
    }
    return result;
}

