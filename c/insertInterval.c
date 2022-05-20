#include <stdio.h>
#include <stdlib.h>

#define MAX(x, y) x > y ? x : y
#define MIN(x, y) x < y ? x : y

int** writeArray(int data[][2], int rowSize, int colSize) {
    int** ret = (int**)malloc(sizeof(int*) * rowSize);
    for (int i = 0; i < rowSize; i++) *ret = (int*)malloc(sizeof(int) * colSize);
    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < colSize; j++) {
            *(ret + (4 * i) + j) = data[i][j];
        }
    }
    return ret;
}

int** merge(int** intervals, int intervalSize, int start, int end, int* newInterval) {
    int newSize = intervalSize - (end - start);
    // Create return array
    int** ret = (int**)malloc(sizeof(int*) * newSize);
    for (int i = 0; i < newSize; i++) *ret = (int*)malloc(sizeof(int) * 2);

    for (int i = 0; i < newSize; i++) {
        // Merging
        int min = INT32_MAX, max = INT32_MIN;
        if (i == start) {
            for (int k = i; k <= end; k++) {
                for (int l = 0; l < 2; l++) {
                    min = MIN(min, intervals[k][l]);
                    max = MAX(max, intervals[k][l]);
                }
            }
            min = MIN(min, newInterval[0]);
            max = MAX(max, newInterval[0]);
            min = MIN(min, newInterval[1]);
            max = MAX(max, newInterval[1]);
        } else {
            min = intervals[i][0];
            max = intervals[i][1];
        }
        ret[i][0] = min;
        ret[i][1] = max;
    }
    return ret;
}
int main() {
    int intervalSize = 5;
    int data[][2] = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    int** intervals = writeArray(data, 5, 2);
    
    printf("Hello world.\n");
}