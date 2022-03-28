#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool canConstruct(char * ransomNote, char * magazine){
    int noteLen = strlen(ransomNote), magaLen = strlen(magazine);
    // Build freq table from magazine
    int freqTable[26] = {0};
    for (int i = 0; i < magaLen; i++) {
        if (magazine[i] != '\0') {
            freqTable[magazine[i] - 'a']++;
        }
    }

    for (int i = 0; i < noteLen; i++) {
        if (ransomNote[i] != '\0') {
            if (freqTable[ransomNote[i] - 'a'] > 0) {
                freqTable[ransomNote[i] - 'a']--;
            } else {
                return false;
            }
        }
    }
    return true;
}

int main() {
    char* r = "aaa"; char* m = "aa";
    printf("%d\n", canConstruct(r, m));
}