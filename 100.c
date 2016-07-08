//
// Created by jiangecho on 16/7/8.
//


#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

//Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct LinkNode {
    struct LinkNode *next;
    struct TreeNode *treeNode;
};

void treeToList(struct LinkNode **head, struct TreeNode *p) {
    if (p->left != NULL) {
        treeToList(head, p->left);
    }

    if (p->right != NULL) {
        treeToList(head, p->right);
    }

    struct LinkNode *node = (struct LinkNode *) malloc(sizeof(struct LinkNode));
    node->treeNode = p;
    (*head)->next = node;
    *head = node;
}


bool isSameTree(struct TreeNode *p, struct TreeNode *q) {
    if (p == NULL && q == NULL) {
        return true;
    } else if (!(p != NULL && q != NULL)) {
        return false;
    }
    struct LinkNode *pl = (struct LinkNode *) malloc(sizeof(struct LinkNode));
    struct LinkNode *ql = (struct LinkNode *) malloc(sizeof(struct LinkNode));

    pl->treeNode = NULL;
    ql->treeNode = NULL;

    treeToList(&pl, p);
    treeToList(&ql, q);

    struct LinkNode *p1 = pl->next;
    struct LinkNode *p2 = ql->next;
    while (true) {
        if (p1 == NULL || p2 == NULL || (p1->treeNode->val != p2->treeNode->val)) {
            break;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    return (p1 == NULL && p2 == NULL) ? true : false;
}
