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

ListNode* reverseList(ListNode* head){
    // Size 0 or 1 case
    if (head == NULL || head->next == NULL) {
        return head;
    }
    ListNode* dummy = createNode(-1);
    dummy->next = head;
    ListNode* prev = head; ListNode* cur = prev->next;
    while (cur != NULL) {
        ListNode* tmp1 = cur;
        // Take cur node out
        prev->next = cur->next;
        cur = cur->next;
        ListNode* tmp2 = dummy->next;
        // Insert cur node at the front
        dummy->next = tmp1;
        tmp1->next = tmp2;
    }
    ListNode* ret = dummy->next;
    free(dummy);
    return ret;
}

int main() {
    int data[] = {6,7,8};
    int size = sizeof(data)/sizeof(int);
    ListNode* a = createList(data, size);
    printList(a);
    ListNode* ret = reverseList(a);
    printList(ret);
}