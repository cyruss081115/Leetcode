#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Binary search on row and column */
bool searchMatrix(int matrix[2][2], int matrixSize, int* matrixColSize, int target){
    int low = 0, high = matrixSize - 1;
    int rowMid, colMid;

    // Row Binary search
    while (low <= high) {
        rowMid = (low + high)/2;
        if (matrix[rowMid][0] == target) {
            return true;
        } else if (matrix[rowMid][0] < target) {
            low = rowMid + 1;
        } else if (matrix[rowMid][0] > target) {
            high = rowMid - 1;
        }
    }
    
    if (matrix[rowMid][0] > target) {
        rowMid--;
    }

    // Reset variables for column binary search
    low = 0; high = matrixColSize[0] - 1;

    // Col Binary search
    while (low <= high) {
        colMid = (low + high)/2;
        if (matrix[rowMid][colMid] == target) {
            return true;
        } else if (matrix[rowMid][colMid] < target) {
            low = colMid + 1;
        } else if (matrix[rowMid][colMid] > target) {
            high = colMid - 1;
        }
    }

    return false;
}

int main() {
    int matrix[2][2] = {
        {1,1},
        {2,2}
    };
    int matrixSize = 2;
    int matrixColSize[2] = {2,2};
    
    printf("%d\n", searchMatrix(matrix, matrixSize, matrixColSize, 0));
}