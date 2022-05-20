#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int lengthOfLongestSubstring(char * s) {
    int len = strlen(s);
    if (len <= 1) 
        return len;
    
    // Define utils
    int global_max = -1; int local_max = 0;
    int freq_table[128];
    memset(freq_table, -1, 128*4);
    int i = 0, j = 0;

    // Slide the window over
    // Store all chars occurance in the window into freqTable
    // Set zero for all chars appeared before that repeated char
    // New i is defined at the repeated char
    // for every cycle, j++
    while (j <= len) {
        // Repeated value
        if (freq_table[s[j]] >= 0 || j == len) {
            local_max = j - i;
            if (local_max > global_max) {
                global_max = local_max;
            }
            local_max = 0;
            // Set null for all chars appeared before that repeated char
            for (;i <= freq_table[s[j]];i++) freq_table[s[i]] = -1;
        }
        freq_table[s[j]] = j;
        j++;
    }
    return global_max;
}

int main () {
    char str[] = "ab";
    printf("%d\n", lengthOfLongestSubstring(str));
}