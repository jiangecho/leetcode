//
// Created by jiangecho on 16/7/16.
//

#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int key;
    int value;
    struct Node *pre;
    struct Node *next;
};

struct Node *head;
int cap;
int count;
bool hasSet = false;

struct Node *get(int key) {
    struct Node *p = head;
    while (p != NULL && key != p->key) {
        p = p->next;
    }
    return p;
}

void update(struct Node *p) {
    if (p == head) {
        return;
    }
    if (p->pre != NULL) {
        p->pre->next = p->next;
    }
    if (p->next != NULL) {
        p->next->pre = p->pre;
    }

    head->pre = p;
    p->next = head;
    head = p;
}

void lruCacheInit(int capacity) {
    head = (struct Node *) malloc(sizeof(struct Node));
    head->next = NULL;
    head->pre = NULL;
    cap = capacity;
    count = 1;
}

void lruCacheFree() {
    // todo

}

int lruCacheGet(int key) {
    if (!hasSet) {
        return -1;
    }
    struct Node *p = get(key);
    int value = -1;
    if (p != NULL) {
        value = p->value;
        update(p);
    }
    return value;
}


void lruCacheSet(int key, int value) {
    if (head->key == key || !hasSet) {
        hasSet = true;
        head->key = key;
        head->value = value;
        return;
    }
    struct Node *p;
    p = get(key);
    if (p != NULL) {
        p->value = value;
    } else if (count == cap) {
        p = head;
        while (p->next != NULL) {
            p = p->next;
        }
        p->key = key;
        p->value = value;

    } else {
        count++;
        p = (struct Node *) malloc(sizeof(struct Node));
        p->key = key;
        p->value = value;
        p->next = NULL;
        p->pre = NULL;
    }

    update(p);
}

