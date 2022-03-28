#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct PosNode {
    /* data */
    int row;
    int col;
    struct PosNode* next;
} PosNode;

typedef struct Table {
    int size;
    struct PosNode** arr;
} Table;

// Note: could be valid but not solvable

Table* createTable(int size) {
    Table* ret = (Table*)malloc(sizeof(Table));
    ret->size = size;
    ret->arr = (PosNode**)malloc(sizeof(PosNode*) * size);
    for (int i = 0; i < size; i++) {
        ret->arr[i] = NULL;
    }
    return ret;
}

PosNode* createNode(int row, int col) {
    PosNode* ret = (PosNode*)malloc(sizeof(PosNode));
    ret->col = col;
    ret->row = row;
    ret->next = NULL;
    return ret;
}

void insert(Table* t, int num, int i, int j) {
    PosNode* p = createNode(i, j);
    if (t->arr[num] == NULL) {
        t->arr[num] = p;
    } else {
        PosNode* tmp = t->arr[num];
        t->arr[num] = p;
        p->next = tmp;
    }
}

bool inSubBox(PosNode* p, int boxNum) {
    // The ranges the be checked
    switch (boxNum)
    {
    case 0:
        return (p->row >= 0 && p->row <= 2) && (p->col >= 0 && p->col <= 2);
    case 1:
        return (p->row >= 0 && p->row <= 2) && (p->col >= 3 && p->col <= 5);
    case 2:
        return (p->row >= 0 && p->row <= 2) && (p->col >= 6 && p->col <= 8);
    case 3:
        return (p->row >= 3 && p->row <= 5) && (p->col >= 0 && p->col <= 2);
    case 4:
        return (p->row >= 3 && p->row <= 5) && (p->col >= 3 && p->col <= 5);
    case 5:
        return (p->row >= 3 && p->row <= 5) && (p->col >= 6 && p->col <= 8);
    case 6:
        return (p->row >= 6 && p->row <= 8) && (p->col >= 0 && p->col <= 2);
    case 7:
        return (p->row >= 6 && p->row <= 8) && (p->col >= 3 && p->col <= 5);
    case 8:
        return (p->row >= 6 && p->row <= 8) && (p->col >= 6 && p->col <= 8);
    
    default:
        printf("Unexpected input!\n");
        return false;
    }
}

bool check(Table* t, int num, int i, int j) {
    int boxNum = (3) * (i / 3) + (j / 3);
    PosNode* cur = t->arr[num];
    if (cur == NULL) {
        insert(t, num, i, j);
        return true;
    }
    while (cur != NULL) {
        if (cur->row == i || cur->col == j) {
            return false;
        } else if (inSubBox(cur, boxNum)) {
            return false;
        } else {
            insert(t, num, i, j);
        } 
        cur = cur->next;
    }
    return true;
}
bool isValidSudoku(char board[9][9], int boardSize, int* boardColSize){
    // No need to init parameters?
    // boardColSize = (int*)malloc(sizeof(int) * 9);
    // for (int i = 0; i < 9; i++) {
    //     boardColSize[i] = 9;
    // }
    Table* t = createTable(9);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == '.') {
                continue;
            } else if (!check(t, (board[i][j] - '0' - 1), i, j)) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    char board[9][9] = {
    {'5','3','.','.','7','.','.','.','.'},
    {'6','.','.','1','9','5','.','.','.'},
    {'.','9','8','.','.','.','.','6','.'},
    {'8','.','.','.','6','.','.','.','3'},
    {'4','.','.','8','.','3','.','.','1'},
    {'7','.','.','.','2','.','.','.','6'},
    {'.','6','.','.','.','.','2','8','.'},
    {'.','.','.','4','1','9','.','.','5'},
    {'.','.','.','.','8','.','.','7','9'}
    };  
    // char** bptr = &(board[0][0]);
    int boardSize = 9;
    int boardColSize[9] = {9,9,9,9,9,9,9,9,9};

    printf("%d", isValidSudoku(board, boardSize, boardColSize));
}