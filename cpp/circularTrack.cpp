#include <iostream>
#include <stdlib.h>
#include <vector>


using namespace std;

class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        // -------- Running and obtain frequency ----------- //
        int *freq = (int*)calloc(n+1, sizeof(int));

        int runner = rounds[0];
        for (int i = 1; i < rounds.size(); i++) {
            while (true) {
                if (runner == rounds[i]) {
                    freq[runner] += 1;
                    runner += 1;
                    if (runner > n) {runner = 1;}
                    break;
                }
                freq[runner] += 1;
                runner += 1;
                if (runner > n) {runner = 1;}
            }
        }

        // ------- Find the largest frequencies in the freq table ------- //
        vector<int> ret;

        int largest = -1;
        for (int i = 1; i < n+1; i++) {
            if (freq[i] > largest) {
                largest = freq[i];
            }
        }
        
        for (int i = 1; i < n+1; i++) {
            if (freq[i] == largest) {
                ret.push_back(i);
            }
        }
        
        return ret;
    }
};

int main() {
    int n = 7;
    vector<int> rounds = {1,3,5,7};
    Solution sol;
    vector<int> ret = sol.mostVisited(n, rounds);
    
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] << " ";
    }
    cout << endl;
}
