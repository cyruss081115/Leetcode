#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ListNode {
	int val;
	struct ListNode* next;
} Node;

Node* createNode(int data) {
	Node* ret = (Node*)malloc(sizeof(Node));
	ret->val = data;
	ret->next = NULL;
	return ret;
}

Node* createList(int arr[], int size) {
	Node* dummy = createNode(-1);
	Node* tmp = dummy;
	for (int i = 0; i < size; i++) {
		tmp->next = createNode(arr[i]);
		tmp = tmp->next;
	}
	Node* ret = dummy->next;
	free(dummy);
	return ret;
}

bool isPalindrome(struct ListNode* head){
	Node* tmp = head; int len = 0;
	while (tmp != NULL) {
		len++;
		tmp = tmp->next;
	}
	int isOdd = len % 2 == 1;
	int mid = isOdd ? (len/2) + 1 : len/2;
	int Stack[mid], top = -1;
	int curPos = 0;

	tmp = head;
	while (tmp != NULL) {
		curPos++;
		if (isOdd) {
			if (curPos == mid) {
				;
			} else if (curPos < mid) {
				Stack[++top] = tmp->val;
			} else {
				if (tmp->val != Stack[top]) {
					return false;
				}
				top--;
			}
		} else {
			if(curPos <= mid) {
				Stack[++top] = tmp->val;
			} else {
				if (tmp->val != Stack[top]) {
					return false;
				}
				top--;
			}
		}
		
		tmp = tmp->next;
	}
	return true;
}

int main() {
	int nums[] = {1, 2};
	int size = 2;
	Node* header = createList(nums, size);
	bool result = isPalindrome(header);
	printf("%d\n", result);
}