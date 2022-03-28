#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int firstUniqChar(char * s){
    int len = strlen(s);
    // Build freq table for each lower case char
    int freqTable[26] = {0};
    for (int i = 0; i < len; i++) {
        if (s[i] != '\0') {
            freqTable[s[i] - 'a'] += 1;
        }
    }
    // Loop through 
    for (int i = 0; i < len; i++) {
        if (s[i] != '\0') {
            if (freqTable[s[i] - 'a'] == 1) {
                return i;
            }
        }
    }
    return -1;
}

int main() {
    char* str = "iloveleetcode";
    printf("%d\n", firstUniqChar(str));
}