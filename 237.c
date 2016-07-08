//
// Created by jiangecho on 16/7/8.
//
//Definition for singly-linked list.
#include <stdio.h>
#include <stdlib.h>
#include "237.h"

struct ListNode {
    int val;
    struct ListNode *next;
};

void deleteNode(struct ListNode *node) {

    struct ListNode *p = node->next;
    if (p != NULL) {
        node->val = node->next->val;
        node->next = node->next->next;
        free(p);
    }

}

void test_237() {
    struct ListNode *p = (struct ListNode *) malloc(sizeof(struct ListNode));
    struct ListNode *p1 = (struct ListNode *) malloc(sizeof(struct ListNode));

    p->next = p1;
    p->val = 0;

    p1->next = NULL;
    p1->val = 1;

    deleteNode(p);
}

