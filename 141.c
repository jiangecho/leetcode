//
// Created by jiangecho on 16/7/9.
//

#include <stdbool.h>
#include <stddef.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

bool hasCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return false;
    }

    struct ListNode *pA = head;
    struct ListNode *pB = head;

    bool result = false;
    while (pA != NULL && pA->next != NULL && pB != NULL && pB->next != NULL && pB->next->next != NULL) {
        pA = pA->next;
        pB = pB->next->next;
        if (pA == pB) {
            result = true;
            break;
        }
    }

    return result;
}

