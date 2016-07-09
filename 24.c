//
// Created by jiangecho on 16/7/9.
//

#include <stddef.h>

//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *swapPairs(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode *p = head;
    struct ListNode *tmp = NULL;
    struct ListNode *pre = NULL;
    struct ListNode *newHead = NULL;
    while (p != NULL && p->next != NULL) {
        tmp = p->next;
        p->next = tmp->next;
        tmp->next = p;
        if (newHead == NULL) {
            newHead = tmp;
        } else{
            pre->next = tmp;
        }
        pre = p;

        p = p->next;
    }
    return newHead;

}


