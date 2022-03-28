#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int **generate(int numRows, int *returnSize, int **returnColumnSizes)
{
    // Allocating memory space
    *returnSize = numRows; 
    *returnColumnSizes = NULL;
    int **ret = malloc(sizeof(int*) * numRows);
    
    for (int i = 1; i <= numRows; i++)
    {
        ret[i - 1] = (int *)malloc(sizeof(int) * i);
    }
    
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            if (j == 0 || i == j) {
                ret[i][j] = 1;
                continue;
            } 
            ret[i][j] = ret[i-1][j-1] + ret[i-1][j];
        }
        
    }
    
    *returnColumnSizes = malloc(sizeof(int) * numRows);
    for (int i = 0; i < numRows; i++) {
        (*returnColumnSizes)[i] = i + 1;
    }
    return ret;
}

int main()
{
    int numRow = 4;
    int returnSize = 2;
    int **returnColSizes = NULL;
    int **ret = generate(numRow, &returnSize, returnColSizes);

    for (int i = 0; i < returnSize; i++) {
        printf("[");
        for (int j = 0; j < (*returnColSizes)[i]; j++) {
            printf("%d ", ret[i][j]);
        }
        printf("], ");
    }

}
