#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
private:
    int getSimilarity(string aStr, string bStr) {
        // Assume both strings are of the same length
        int ret = 0;
        for (int i = 0; i < aStr.size(); i++) {
            if (aStr[i] != bStr[i])
                ret++;
        }
        return ret;
    }
    
    int minMutationHelper(string start, string end, vector<string>& bank, int cur_count) {
        if (start == end) {
            return cur_count;
        } else if (bank.size() == 0) {
            return -1;
        }
        
        // Find and remove current visiting element
        vector<string> curBank(bank);
        vector<string>::iterator it = curBank.begin();
        for (it = curBank.begin(); it != curBank.end(); it++) {
            if (*it == start) {
                curBank.erase(it);
                break;
            }
        }
        
        // Create table for computing similarity
        map<string, int> simTable;
        for (it = curBank.begin(); it != curBank.end(); it++){
            int sim = getSimilarity(start, *it);
            simTable.insert(pair<string, int>(*it, sim));
        }
        
        // Find minimum 
        int min = 10000;
        cout << "[DEBUG] Currently at: " << start << " cur_count: " << cur_count << endl;
        for (int i = 0; i < simTable.size(); i++) {
            cout << "Visiting: " << curBank[i] << endl;
            if (simTable.at(curBank[i]) == 1) {
                int tmp = minMutationHelper(curBank[i], end, curBank, cur_count+1);
                if (tmp < min && tmp >= 0) {
                    min = tmp;
                }
            }
        }
        cout << "[DEBUG] Currently at: " << start << " return val: " << ((min == 10000) ? -1 : min) << endl;
        return (min == 10000) ? -1 : min; 
    }
public:
    int minMutation(string start, string end, vector<string>& bank) {
        return minMutationHelper(start, end, bank, 0);
    }
};

int main() {
    string start = "AACCGGTT";
    string end = "AAACGGTA";
    vector<string> bank = {"AACCGGTA", "AACCGCTA", "AAACGGTA"};
    Solution sol;
    cout << sol.minMutation(start, end, bank) << endl;
}
