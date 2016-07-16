#include <cstdlib>

//
// Created by jiangecho on 16/7/16.
//
class MinStack {
    int *pBottom;
    int *pTop;
    int *pCur;

    int step = 1024;
    int min = INT32_MAX;
    bool minValid = true;

public:
    /** initialize your data structure here. */
    MinStack() {
        pTop = (int *) malloc(sizeof(int) * step);
        pCur = pBottom = pTop;
    }

    void push(int x) {
        min = min < x ? min : x;
        if (pCur == pTop) {
            int len = (int) (pTop - pBottom);
            pBottom = (int *) realloc(pBottom, sizeof(int) * (len + step));
            pCur = pBottom + len;
            pTop = pBottom + len + step;
        }
        *pCur++ = x;

    }

    void pop() {
        minValid = false;
        pCur--;
    }


    int top() {
        return *(pCur - 1);
    }

    int getMin() {
        if (minValid){
            return min;
        }

        int *p = pBottom;
        int min = *p;
        while (p < pCur) {
            min = min < *p ? min : *p;
            p++;
        }
        this->min = min;
        this->minValid = true;
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

