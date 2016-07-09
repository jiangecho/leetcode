//
// Created by jiangecho on 16/7/9.
//

#include <stddef.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *deleteDuplicates(struct ListNode *head) {
    struct ListNode *p = head;
    struct ListNode *tmp;
    while (p != NULL && p->next != NULL) {
        if (p->val == p->next->val) { // remove
            tmp = p->next;
            p->next = p->next->next;
            free(tmp);
        } else {
            p = p->next;
        }
    }

    return head;
}

