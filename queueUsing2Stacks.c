#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



typedef struct {
    int* inbox;
    int inTop;
    int* outbox;
    int outTop;
    int boxSize;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue* q = (MyQueue*)malloc(sizeof(MyQueue));
    q->boxSize = 300;
    q->inbox = (int*)malloc(sizeof(int) * 300);
    q->outbox = (int*)malloc(sizeof(int) * 300);
    q->inTop = -1;
    q->outTop = -1;
    return q;
}

void myQueuePush(MyQueue* obj, int x) {
    obj->inbox[++(obj->inTop)] = x;
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->inTop == -1 && obj->outTop == -1;
}

int myQueuePop(MyQueue* obj) {
    if (obj->outTop == -1){
        // Pop all elements from inbox and push them to outbox
        while (obj->inTop > -1) {
            obj->outbox[++(obj->outTop)] = obj->inbox[(obj->inTop)--];
        }
    }
    
    return obj->outbox[(obj->outTop)--];
    
}

int myQueuePeek(MyQueue* obj) {
    if (obj->outTop == -1){
        // Pop all elements from inbox and push them to outbox
        while (obj->inTop > -1) {
            obj->outbox[++(obj->outTop)] = obj->inbox[(obj->inTop)--];
        }
    }
    
    return obj->outbox[(obj->outTop)];
}



void myQueueFree(MyQueue* obj) {
    free(obj->inbox);
    free(obj->outbox);
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

int main() {
    MyQueue* q = myQueueCreate();
    myQueuePush(q, 1);
    myQueuePush(q, 2);
    myQueuePush(q, 3);
    myQueuePush(q, 4);
    // printf("Peek: %d\n", myQueuePeek(q));
    printf("Pop: %d\n", myQueuePop(q));
    myQueuePush(q, 5);
    printf("Pop: %d\n", myQueuePop(q));
    printf("Pop: %d\n", myQueuePop(q));
    printf("Pop: %d\n", myQueuePop(q));
    printf("Pop: %d\n", myQueuePop(q));
    printf("isEmpty: %d\n", myQueueEmpty(q));
}