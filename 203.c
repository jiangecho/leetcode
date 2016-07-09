//
// Created by jiangecho on 16/7/9.
//

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *removeElements(struct ListNode *head, int val) {
    if (head == NULL) {
        return head;
    }

    struct ListNode *p = head;
    struct ListNode *pre = NULL;
    while (head != NULL) {
        if (head->val == val) {// is the first element
            if (p == head) {
                p = head->next;
            } else {
                pre->next = head->next;
            }
            free(head);
            head = head->next;
        } else {
            pre = head;
            head = head->next;
        }
    }

    return p;
}
