#include <stdlib.h>
#include <iostream>

using namespace std;

class Solution{
    public:
        bool isMatch(string s, string p){
            int p_len = p.length();
            int s_len = s.length();

            if (p_len == 0){
                return false;
            } 
            // possible to check p = * and s = "" ?
            int len = p.length();
            bool isStar = false;
            int p_ptr = 0; int s_ptr = 0;

            while (p_ptr < p_len) {
                cout << "s[s_ptr]: " << s[s_ptr] << " p[p_ptr]: " << p[p_ptr] << endl;

                if (s[s_ptr] == p[p_ptr]) {
                    // When both string at has the same char at where ptr is pointing
                    // simply go to the next char if no star is read previously
                    // reset star if star is read and the same char is detected 
                    if (isStar == false) {
                        s_ptr++;
                        p_ptr++;
                    } else {
                        isStar = false;
                        p_ptr++;
                        s_ptr++;
                    }
                } else if (p[p_ptr] == '?') {
                    // Go the next char if '?' is read at p
                    s_ptr++;
                    p_ptr++;
                } else if (p[p_ptr] == '*'){
                    if (p[p_ptr + 1] == s[s_ptr]) {
                        p_ptr++;
                    } else  {
                        // Set star
                        isStar = true;
                        p_ptr++;
                        s_ptr++;
                    }
                } else if (p[p_ptr] != s[s_ptr]) {
                    // When both ptrs does not agree,
                    // if isStar is true, move to the next char for the string
                    // else, the string does not match, reject.
                    if (isStar == true) {
                        s_ptr++;
                    } else {
                        return false;
                    }
                }
            }


            while (isStar && s_ptr < s_len) {
                s_ptr++;
            }

            cout << "s_ptr: " << s_ptr << " p_ptr: " << p_ptr << endl;

            if ((s_ptr == s_len) && (p_ptr == p_len)) {
                return true;
            }
            return false;
        }
};

int main() {
    string s = "";
    string p = "**";

    Solution sol;
    cout << (sol.isMatch(s, p) ? "true" : "false") << endl;
    
    
}
