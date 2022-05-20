#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
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

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* retHead = createNode(-1); ListNode* curRet = retHead;
    ListNode* cur1 = list1; ListNode* cur2 = list2;
    while (cur1 != NULL && cur2 != NULL) {
        if (cur1->val <= cur2->val) {
            curRet->next = createNode(cur1->val);
            cur1 = cur1->next;
        } else {
            curRet->next = createNode(cur2->val);
            cur2 = cur2->next;
        }
        curRet = curRet->next;
    }
    // Merge to the list if there is still unmerged nodes
    if (cur1 != NULL) {
        while (cur1 != NULL) {
            curRet->next = createNode(cur1->val);
            cur1 = cur1->next;
            curRet = curRet->next;
        }   
    }

    if (cur2 != NULL) {
        while (cur2 != NULL) {
            curRet->next = createNode(cur2->val);
            cur2 = cur2->next;
            curRet = curRet->next;
        }   
    }
    curRet = retHead->next;
    free(retHead);
    return curRet;
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

int main() {
    int arr[] = {1,2,4}; int brr[] = {1,3,4};
    ListNode* a = createList(arr, 3);
    ListNode* b = createList(brr, 3);
    ListNode* ret = mergeTwoLists(a, b);
    printList(a); printList(b);
    printList(ret);
    freeList(a);
    freeList(b);
    freeList(ret);
}