#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:

        bool isUniqueConcat(vector<string>& toCat) {
            int freq[26] = {0};
            for (string aString: toCat)  {
                int strlen = aString.length();
                for (int i = 0; i < strlen; i++) {
                    if (freq[aString[i] - 'a'] == 0) {
                        freq[aString[i] - 'a'] = 1;
                    } else {
                        return false;
                    }
                }
            }
            return true;
        }

        int getLength(vector<string>& toCat) {
            int ret = 0;
            for (string str: toCat) {
                ret += str.length();
            }
            return ret;
        }

        int maxLength(vector<string>& arr) {
            int n = arr.size();
            int max = -1;

            for (int i = 0; i < n; i++) {
                vector<string> current;
                current.push_back(arr[i]);

                for (int j = 0; j < n; j++) {
                    if (i == j) {
                        continue;
                    } 

                    current.push_back(arr[j]);

                    if (!isUniqueConcat(current)) {
                        current.pop_back(); 
                    }
                    
                    if (getLength(current) > max) {
                        max = getLength(current);
                    }
                
                    
                }
            }
            return max; 
        }
        
};

int main() {
    Solution sol;
    vector<string> arr  = {"un","iq","ue"};
    vector<string> brr = {"aa"};
    cout << sol.isUniqueConcat(brr) << endl;

    cout << sol.maxLength(arr)<< endl;
}
