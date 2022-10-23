#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

struct comparator {
    bool operator() (pair<int, int>& a, pair<int, int>& b) {
        // put b on top if larger
        return a.second < b.second;
    }
};

class Solution {
    public:
        vector<int> topKFrequent(vector<int>& nums, int k) {
            vector<int> ret;

            map<int, int> m;
            map<int, int>:: iterator it = m.begin();
            
            for (int aNum: nums) {
                it = m.find(aNum);
                if (it == m.end()){
                    m.insert(pair<int, int>(aNum, 1));
                } else {
                    it->second++;
                }
            }

            priority_queue<pair<int, int>, vector<pair<int, int> >, comparator> pq;

            for (it = m.begin(); it != m.end(); it++) {
                pq.push(pair<int, int>(it->first, it->second)) ;
            } 

            for (int i = 0; i < k; i++) {
                ret.push_back(pq.top().first);
                pq.pop();
            }
            
            return ret;
        }
};

int main() {
    int k = 2;
    vector<int> nums = {1,1,1,1,1,1, 2,2,2, 3,3,3,3};
    Solution sol;
    vector<int> ret = sol.topKFrequent(nums, k);

    for (int i: ret) {
        cout << i << " ";
    }

    cout << endl;
    
}
