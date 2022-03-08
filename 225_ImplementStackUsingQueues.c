/*
* @Author: zero
* @Date:   2021-07-11 15:53:24
* @Description: Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).
*/
#define MaxSize 101
typedef struct {
    int data[MaxSize];
    int front;
    int rear;
} Queue;

typedef struct {
    Queue *Q;
} MyStack;

bool isEmptyQueue(Queue* Q) {
    if (Q->rear == Q->front)
        return true;
    return false;
}

void initQueue(Queue* Q) {
    Q = (Queue*)malloc(sizeof(Queue));
    S->Q->front = S->Q->rear = 0;
}

void queuePush(Queue* Q, int x) {
    Q->data[++(Q->rear) % MaxSize] = x;
}

int queuePop(Queue* Q) {
    return Q->data[++(Q->front) % MaxSize];
}

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack *S = (MyStack*)malloc(sizeof(MyStack));
    initQueue(S->Q);
    return S;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    queuePush(obj->Q, x);
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    int flag = obj->Q->rear;
    while ((obj->Q->front + 1) % MaxSize != flag) {
        queuePush(obj->Q, queuePop(obj->Q));
    }
    return queuePop(obj->Q);
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    return obj->Q->data[obj->Q->rear];
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    return isEmptyQueue(obj->Q);
}

void myStackFree(MyStack* obj) {
    free(obj->Q);
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/
