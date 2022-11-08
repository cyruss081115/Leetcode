#include <iostream>
#include <list>

using namespace std;

class Solution {
public:
    string makeGood(string s) {
      // Create table to store which entry is valid which is not
      string ret = "";
      list<char> l;
      for (char c: s) {
        // Lower character and it matches with the tail of list
        if (abs(c - l.back()) == 32) {
          l.pop_back(); 

        } else {
          l.push_back(c);
        }
      }

      for (list<char>:: iterator it = l.begin(); it != l.end(); it++) {
        ret += *it;
      }
        
      return ret;
    }
};

int main() {
  string s = "leEeetcode";
  Solution sol;
  cout << sol.makeGood(s) << endl;
}
