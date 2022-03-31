#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ListNode {
    int val;
    struct ListNode* next;
} ListNode;

// Min Heap
typedef struct Heap {
    int maxSize;
    int curSize;
    struct ListNode** elements;
} Heap;

// Linked List Utils
ListNode* createNode(int val);
ListNode* createList(int data[], int size);
void printList(ListNode* head);
void freeList(ListNode* head);

// Heap utils
Heap* initHeap(ListNode** elements, int maxSize);
int isEmpty(Heap* h);
void Heapify(Heap* h, int rootPos);
int pop(Heap* h);
void printHeap(Heap* h);

// General Utils
void swap(ListNode* a, ListNode* b);

int main() {
    int arr[] = {9,8,7};
    int aSize = sizeof(arr)/sizeof(int);
    int brr[] = {6,5,4};
    int bSize = sizeof(brr)/sizeof(int);
    int crr[] = {3,2,1};
    int cSize = sizeof(crr)/sizeof(int);
    ListNode* a = createList(arr, aSize);
    printList(a);
    ListNode* b = createList(brr, bSize);
    printList(b);
    ListNode* c = createList(crr, cSize);
    printList(c);
    ListNode** ele = (ListNode**)malloc(sizeof(ListNode*) * 3);
    ele[0] = a; ele[1] = b; ele[2] = c;
    int listSize = 3;
    Heap* h = initHeap(ele, listSize);
    printHeap(h);
    printf("testing\n");
}

ListNode* createNode(int val) {
    ListNode* ret = malloc(sizeof(ListNode));
    ret->val = val;
    ret->next = NULL;
    return ret;
}

ListNode* createList(int data[], int size) {
    if (size == 0) {
        return NULL;
    }
    ListNode* head = createNode(data[0]);
    ListNode* cur = head;
    for (int i = 1; i < size; i++) {
        cur->next = createNode(data[i]);
        cur = cur->next;
    }
    return head;
}

void printList(ListNode* head) {
    ListNode* cur = head;
    while (cur != NULL) {
        printf("%d ", cur->val);
        cur = cur->next;
    }
    printf("\n");
}

void freeList(ListNode* header) {
    ListNode* cur = header;
    while (cur->next != NULL) {
        ListNode* tmp = cur->next;
        free(cur);
        cur = tmp;
    }
    header->next = NULL;
}

void swap(ListNode* a, ListNode* b) {
    ListNode tmp = *a;
    *a = *b;
    *b = tmp;
}

Heap* initHeap(ListNode** elements, int maxSize) {
    Heap* ret = (Heap*)malloc(sizeof(Heap));
    ret->maxSize = maxSize;
    ret->curSize = maxSize;
    ret->elements = elements;
    for (int i = (maxSize/2) - 1; i >= 0; i--) {
        Heapify(ret, i);
    }
    return ret;
}

void Heapify(Heap* h, int rootPos) {
    int left = (2 * rootPos) + 1;
    int right = (2 * rootPos) + 2;
    int smallest = rootPos;
    if (left <= h->curSize && h->elements[left]->val < h->elements[smallest]->val) {
        smallest = left;
    }
    if (right <= h->curSize && h->elements[right]->val < h->elements[smallest]->val) {
        smallest = right;
    }
    if (smallest != rootPos) {
        swap(h->elements[rootPos], h->elements[smallest]);
        Heapify(h, smallest);
    }
}

int isEmpty(Heap* h) {
    return h->curSize == 0;
}

int pop(Heap* h) {
    if (isEmpty(h)) {
        printf("The heap is empty!");
        return -1;
    }
    ListNode* tmp = h->elements[0];
    int ret = tmp->val;
    h->elements[0] = h->elements[0]->next;
    free(tmp); // Pop out
    if (h->elements[0] == NULL) {
        swap(h->elements[0], h->elements[--(h->curSize)]);
    }
    Heapify(h, 0);
    return ret;
}

void printHeap(Heap* h) {
    int len = h->curSize;
    for (int i = 0; i < len; i++) {
        printf("%d ", h->elements[i]->val);
    }
    printf("\n");
}