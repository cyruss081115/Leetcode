#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode* next;
} ListNode;

ListNode* createNode(int val) {
    ListNode* ret = (ListNode*)malloc(sizeof(ListNode));
    ret->val = val;
    ret->next = NULL;
    return ret;
}

ListNode* createList(int data[], int size) {
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



ListNode* removeElements(ListNode* head, int target){
    ListNode* dummy = createNode(-1);
    dummy->next = head;
    ListNode* prev = dummy; ListNode* cur = dummy->next;
    while (cur != NULL) {
        // If targeted elemene is detected, remove
        if (cur->val == target) {
            ListNode* tmp = cur;
            cur = cur->next;
            prev->next = cur;
            free(tmp);
        } else {
            // Not our target
            prev = prev->next;
            cur = cur->next;
        }
    }
    ListNode* ret = dummy->next;
    free(dummy);
    return ret;
}

int main() {
    int arr[] = {2,2,2,2,2,2};
    int size = sizeof(arr)/sizeof(int);
    ListNode* a = createList(arr, size);
    printList(a);
    ListNode* new = removeElements(a, 2);
    printList(new);
}