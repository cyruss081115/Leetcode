#include <stdio.h>
#include <stdlib.h>


int maxProfit(int* prices, int pricesSize){
    int i = 0, j = 1, max = 0;
    while (j < pricesSize) {
        if (prices[j] - prices[i] > 0 && prices[j] - prices[i] > max) {
            max = prices[j] - prices[i];
        }
        if (prices[j] < prices[i]) {
            i = j;
        }
        j++;
    }
    return max;
}

int main() {
    int prices[] = {8, 1, 4, 5, 3, 2};
    int size = sizeof(prices) / sizeof(int);
    
    printf("%d\n", maxProfit(prices, size));
}