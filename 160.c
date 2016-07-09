//
// Created by jiangecho on 16/7/9.
//
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if (headA == NULL || headB == NULL) {
        return NULL;
    }

    int lenA = 0;
    int lenB = 0;
    struct ListNode *pA = headA;
    struct ListNode *pB = headB;

    while (pA != NULL) {
        lenA++;
        pA = pA->next;
    }

    while (pB != NULL) {
        lenB++;
        pB = pB->next;
    }

    pA = headA;
    pB = headB;
    for (int i = 0; i < lenA - lenB; ++i) {
        pA = pA->next;
    }

    for (int j = 0; j < lenB - lenA; ++j) {
        pB = pB->next;
    }

    while (pA != pB) {
        pA = pA->next;
        pB = pB->next;
    }

    return pA;
}

