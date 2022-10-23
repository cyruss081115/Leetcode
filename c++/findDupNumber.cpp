#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        // Using the Floyd's Tortoise and Hare Algorithm for cycle detection
        // if there contains duplicate in the list of numbers, there must exist
        // a cycle when we map the corresponding values.
        // The entrance of such cycle is then the duplicated number
        int findDuplicate(vector<int>& nums) {
            int tortoise = nums[0];
            int hare = nums[0];

            // Phase 1 that finds the intersection point
            do {
                tortoise = nums[tortoise];
                hare = nums[nums[hare]];
            } while (tortoise != hare);

            // After the loop, both of them should reach the same point
            // aka the intersection point

            // Phase 2 to find the entrance of cycle
            // first place the tortoise to the beginning
            // the hare start at the intersection

            tortoise = nums[0];
            while (tortoise != hare) {
                tortoise = nums[tortoise];
                hare = nums[hare];
            }

            return hare;
        }
};

int main() {
    vector<int> nums = {1,3,4,2,2};
    Solution sol;
    cout << sol.findDuplicate(nums) << endl;

}
