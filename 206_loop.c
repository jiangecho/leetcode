//
// Created by jiangecho on 16/7/9.
//
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *reverseList(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode *tail = head;
    struct ListNode *newHead;

    while (tail->next != NULL) {
        tail = tail->next;
    }
    newHead = tail;

    do {
        tail->next = head;
        head = head->next;
        tail = tail->next;
    } while (head != newHead);

    return newHead;
}