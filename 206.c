
//
// Created by jiangecho on 16/7/9.
//
//* Definition for singly-linked list.

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *reverseList(struct ListNode *head) {
    if (head == NULL) {
        return head;
    }
    struct ListNode *p;
    struct ListNode *q;
    if (head->next != NULL) {
        p = reverseList(head->next);
        q = p;
        while (q->next != NULL) {
            q = q->next;
        }
        q->next = head;
        head->next = NULL;
        return p;
    } else {
        return head;
    }
}

