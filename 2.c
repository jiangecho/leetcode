//
// Created by jiangecho on 16/7/8.
//
//* Definition for singly-linked list.
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {

    if (l1 == NULL) {
        return l2;
    } else if (l2 == NULL) {
        return l1;
    }

    struct ListNode *head = l1;
    struct ListNode *pre = NULL;
    while (l1 != NULL && l2 != NULL) {
        l1->val += l2->val;
        pre = l1;
        l1 = l1->next;
        l2 = l2->next;
    }

    if (l2 != NULL) {
        pre->next = l2;
    }

    struct ListNode *tmp = head;
    while (tmp != NULL) {
        if (tmp->val >= 10) {
            tmp->val -= 10;
            if (tmp->next != NULL) {
                tmp->next->val += 1;
            } else {
                tmp->next = (struct ListNode *) malloc(sizeof(struct ListNode));
                tmp->next->val = 1;
                tmp->next->next = NULL;

            }
        }

        tmp = tmp->next;
    }

    return head;
}

