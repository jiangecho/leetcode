//
// Created by jiangecho on 16/7/10.
//

#include <stddef.h>
#include <stdlib.h>

//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    if(head== NULL || n < 0){
        return head;
    }

    int length = 0;
    struct ListNode* p = head;
    while (p != NULL){
        length ++;
        p = p->next;
    }
    p = head;
    struct ListNode* pre = NULL;
    for (int i = 0; i < length; ++i) {
        if(i + n == length){
            if (pre == NULL){
                head = head->next;
            } else{
                pre->next = p->next;
            }
            free(p);
            break;
        } else{
            pre = p;
            p = p->next;
        }
    }

    return head;
}

