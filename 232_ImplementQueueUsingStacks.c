/*
* @Author: zero
* @Date:   2021-07-10 09:36:20
* @Description: Implement a first in first out (FIFO) queue using only two stacks.
* The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MaxSize 100

typedef struct {
    int *data;
    int top;
} Stack;

typedef struct {
    Stack *in;
    Stack *out;
} MyQueue;

/** Initialize your data structure here. */

MyQueue *myQueueCreate() {
    MyQueue *queue = (MyQueue *) malloc(sizeof(MyQueue));
    queue->in = (Stack *) malloc(sizeof(Stack));
    queue->out = (Stack *) malloc(sizeof(Stack));
    queue->in->data = (int *) malloc(sizeof(int) * MaxSize);
    queue->out->data = (int *) malloc(sizeof(int) * MaxSize);
    queue->in->top = -1;
    queue->out->top = -1;
    return queue;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue *obj, int x) {
    obj->in->data[++(obj->in->top)] = x;
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue *obj) {
    if (obj->out->top == -1) {
        while (obj->in->top > -1) {
            obj->out->data[++(obj->out->top)] = obj->in->data[(obj->in->top)--];
        }
    }
    return obj->out->data[(obj->out->top)--];
}

/** Get the front element. */
int myQueuePeek(MyQueue *obj) {
    if (obj->out->top == -1) {
        while (obj->in->top > -1) {
            obj->out->data[++(obj->out->top)] = obj->in->data[(obj->in->top)--];
        }
    }
    return obj->out->data[obj->out->top];
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue *obj) {
    if (obj->in->top == -1 && obj->out->top == -1)
        return true;
    return false;
}

void myQueueFree(MyQueue *obj) {
    free(obj->in->data);
    free(obj->out->data);
    free(obj->in);
    free(obj->out);
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/
