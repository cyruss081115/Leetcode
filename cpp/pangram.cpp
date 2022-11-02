#include <iostream>

using namespace std;

class Solution {
    public:
        bool checkIfPangram(string sentence){
            int table[26] = {0};

            for (int i = 0; i < sentence.length(); i++) {
                if (isalpha(sentence[i]) != 0) {
                    table[sentence[i] - 'a']++;
                }
            }

            for (int i = 0; i < 26; i++) {
                if (table[i] == 0) {
                    return false;
                }
            }
            return true;
        }
};

int main() {
    string s = "thequickbrownfoxjumpsoverthelazydog";

    Solution sol;
    cout << (sol.checkIfPangram(s) ? "true" : "false") << endl;
}
