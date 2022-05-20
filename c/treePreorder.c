#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

int countNode(TreeNode* t) {
    if (t == NULL) {
        return 0;
    } else {
        return countNode(t->left) + countNode(t->right) + 1;
    }
}

void preOrderHelper(TreeNode* t, int* arr, int* cur) {
    if (t == NULL) {
        return;
    }
    // Root
    arr[++(*cur)] = t->val;
    // Left
    preOrderHelper(t->left, arr, cur);
    // Right
    preOrderHelper(t->right, arr, cur);
}

int* preorderTraversal(TreeNode* root, int* returnSize){
    *returnSize = 0; int cur = -1;
    *returnSize = countNode(root);
    int* arr = (int*)malloc(sizeof(int) * (*returnSize));
    preOrderHelper(root, arr, &cur);
    return arr;
}

int main() {
    printf("No output.\n");
}