#include <iostream>

using namespace std;

class Solution {
    public:

        // You are given a string s and an integer k. 
        // You can choose one of the first k letters of s and append it at the end of the string..
        // Return the lexicographically smallest string you could have after applying the mentioned step any number of moves.
        string orderlyQueue(string s, int k) {
            string tmpStr = s;
            // For k==2, we know that two character can be swapped by first putting the first character to the back
            // then continuously putting the 2nd character to the back, until the first character appears again. 
            // e.g. ab.... --> b...a --> b..a. --> b.a.. --> ba...
            // When swapping works, recall bubble sort, we can then sort the string according to the lexicographical order
            if (k > 1) {
                sort(tmpStr.begin(), tmpStr.end());
                return tmpStr;
            }

            // If k == 1, find the lexicographically smallest substring with length = s.len for string s+s
            tmpStr += s;
            string curMin = s;
            for (int i = 0; i < s.length(); i++) {
                curMin = min(curMin, tmpStr.substr(i, s.length()));
            }

            return curMin;
        }
};

int main () {
    string s = "cba";
    int k = 1;
    Solution sol;
    cout << sol.orderlyQueue(s, k) << endl;
}
