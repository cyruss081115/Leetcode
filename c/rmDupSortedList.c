#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode* next;
} ListNode;

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

ListNode* deleteDuplicates(ListNode* head){
    if (head == NULL || head->next == NULL) {
        return head;
    }
    ListNode* prev = head; ListNode* cur = prev->next;
    while (cur != NULL) {
        if (prev->val == cur->val) {
            ListNode* tmp = cur;
            cur = cur->next;
            prev->next = cur;
            free(tmp);
        } else {
            cur = cur->next;
            prev = prev->next;
        }
    }
    return head;
}

int main () {
    int arr[] = {1,1,2,3,3,4,5,6,6,6,6,7,7,7,8,8,8,9};
    int size = sizeof(arr)/sizeof(int);
    ListNode* a = createList(arr, size);
    printList(a);
    ListNode* ret = deleteDuplicates(a);
    printList(ret);
}