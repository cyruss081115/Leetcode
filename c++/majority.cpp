#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
    public:
        int majorityElement(vector<int>& nums) {

            map<int, int> table;

            for (int i = 0; i < nums.size(); i++) {
                map<int, int>::iterator it = table.find(nums[i]);

                if (it == table.end()){
                    table.insert(pair<int, int>(nums[i], 1));
                } else {
                    it->second = it->second + 1;
                }
            }

            int maxVal = 0;
            int majorityElement = 99999;

            for (map<int, int>::iterator i = table.begin(); i != table.end(); i++){
                if (i->second >= maxVal) {
                    maxVal = i->second;
                    majorityElement = i->first;
                }
            }
            return majorityElement;
        }
};

int main() {
    vector<int> vector1{2,2,1,1,1,2,2};

    Solution sol;
    cout << sol.majorityElement(vector1) << endl;
}
