#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int> diff;

        for (int i = 0; i < capacity.size(); i++) {
            diff.push_back(capacity[i] - rocks[i]);
        }

        sort(diff.begin(), diff.end());

        int remaining_rocks = additionalRocks;
        int num_bags_full = 0;


        for (auto bag: diff) {
            if (bag <= remaining_rocks) {
                remaining_rocks -= bag;
                num_bags_full++;
                continue;
            }
            break;
        }
        
        return num_bags_full;
    }
};

int main() {
    vector<int> capacity = {10,2,2};
    vector<int> rocks = {2,2,0};
    int additionalRocks = 100;

    Solution sol;

    cout << sol.maximumBags(capacity, rocks, additionalRocks) << endl;

    return 0;
}
