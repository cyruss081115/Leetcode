#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    // elements in words consist of 2 characters, concat these characters to form 
    // longest possible palindrome, they can only be used once.
    // First thoughts;
    // Greedy approach: If there exist a pair of words that is palindrome to each other
    // those must be in the final longest palindrome
    // Algorithm;
    // For each elements in words:
    //  find its corresponding pair in hash table
    //  mark pairs that has duplicated characters
    // For each pair:
    //  use stack to construct such pair
    //  (+4)
    // If there is duplicated element that is not used
    // add it to the centre of string (+2)
    // return the count.
    int longestPalindrome(vector<string>& words) {
        int ret = 0;
        unordered_map<string, int> m;
        for (string s: words) {
            string rev = s;
            reverse(rev.begin(), rev.end());
            if (m[rev] > 0) {
                ret += 4;
                m[rev]--;
            } else {
                m[s]++;
            }
        }

        for (auto remaining: m) {
            if (remaining.first[0] == remaining.first[1] && remaining.second > 0) {
                return ret + 2;
            }
        }

        return ret;
    }
};

int main() {
    vector<string> words = {"ll","lb","bb","bx","xx","lx","xx","lx","ll","xb","bx","lb","bb","lb","bl","bb","bx","xl","lb","xx"};
    Solution sol;
    cout << sol.longestPalindrome(words) << endl;
    
}
