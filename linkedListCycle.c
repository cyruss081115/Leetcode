#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

bool hasCycle(struct ListNode *head) {
    // fast & slow method
    if (head == NULL || head->next == NULL) {
        return false;
    }
    struct ListNode* fast = head->next; 
    struct ListNode* slow = head; 

    while (fast != NULL && fast->next != NULL && slow != NULL) {
        if (fast == slow) {
            return true;
        }
        fast = fast->next->next;
        slow = slow->next;
    }
    return false;
}

int main() {
    printf("testing\n");
}