#include <stdbool.h>
#include <stdlib.h>
#include <memory.h>

//
// Created by jiangecho on 16/7/16.
//
typedef struct {
    int *values;
    int top;
} Queue;


/* Create a queue */
void queueCreate(Queue *queue, int maxSize) {
    queue->values = (int *) malloc(sizeof(int) * maxSize);
    queue->top = 0;
}

/* Push element x to the back of queue */
void queuePush(Queue *queue, int element) {
    int *p = queue->values + queue->top;
    *p = element;
    queue->top++;

}

/* Removes the element from front of queue */
void queuePop(Queue *queue) {
    //queue->values = queue->values + 1; //bug here, can not modify the values pointer
    // use loop to move element
    //memcpy(queue->values, queue->values + 1, queue->top ); // the memory is overlap, so ...
    for (int i = 0; i < queue->top - 1; ++i) {
        queue->values[i] = queue->values[i + 1];
    }
    queue->top--;

}

/* Get the front element */
int queuePeek(Queue *queue) {
    return *(queue->values);

}

/* Return whether the queue is empty */
bool queueEmpty(Queue *queue) {
    return queue->top == 0;

}

/* Destroy the queue */
void queueDestroy(Queue *queue) {
    if (queue->values == NULL) {
        return;
    }
    free(queue->values);
    queue->top = 0;
    queue->values = NULL;
}

