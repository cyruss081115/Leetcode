#include <iostream>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
      int i = 0; 
      while (i < s.length()) {
        if (s[i] == s[i+1]) {
          s = s.erase(i, 2);
          i--;
          if (i < 0) i = 0;
        } else {
          i++;
        }
      }
      return s;
    }
};

int main() {
  string s = "azxxzy";
  Solution sol;
  cout << sol.removeDuplicates(s) << endl;
}
