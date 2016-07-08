//
//  21.c
//  leetcode
//
//  Created by jiangecho on 16/7/7.
//  Copyright © 2016年 jiangecho. All rights reserved.
//

#include "21.h"
#include <stdio.h>

  //Definition for singly-linked list.
  struct ListNode {
      int val;
      struct ListNode *next;
 };

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* p = NULL;
    struct ListNode* head = NULL;

    if (l1 == NULL) {
        return l2;
    }
    
    if (l2 == NULL) {
        return l1;
    }
    
    while (l1 != NULL && l2 != NULL) {
        if (p == NULL ) {
            if (l1->val < l2->val) {
                p = l1;
                l1 = l1->next;
            }else{
                p = l2;
                l2 = l2->next;
            }
            head = p;
        }else{
            if (l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
            }else{
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
    }
    
    if (l1 != NULL ) {
        p->next = l1;
    }else if(l2 != NULL){
        p->next = l2;
    }
    
    
    return head;
}
