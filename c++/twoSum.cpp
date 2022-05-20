#include <iostream>
#include <vector>
using namespace std;

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // brute force
        int i, j;
        vector<int> ret(2, 0);
        for (i = 0; i < nums.size(); i++) {
            for (j = i + 1; j < nums.size(); j++) {
                if (nums.at(i) + nums.at(j) == target) {
                    ret.at(0) = i; ret.at(1) = j;
                    return ret;
                }
            }
        }
        return ret;
    }  
};

int main() {
    Solution s;
    vector<int> vector1 = {1, 2, 3, 4, 5};
    vector<int> result = s.twoSum(vector1, 3);
    cout << result.at(0) << "," << result.at(1) << endl;
    cout << "Hello World" << endl;
}
