#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>


using namespace std;

struct comparator {
    bool operator() (pair<string, int>& a, pair<string, int>& b) {
        // Same frequency
        if (a.second == b.second) {
            // smaller lexigraphical value on top
            return a.first > b.first;
        } else {
            // larger frequency on top
            return a.second < b.second;
        }
    } 
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {

        k = min(k, (int)words.size());
        vector<string> ret;

        // Use hash map to store frequencies of words
        map<string, int> m;
        map<string, int>::iterator it = m.begin();

        for (string aWord: words) {
            it = m.find(aWord);
            if (it == m.end()) {
                m.insert(pair<string, int>(aWord, 1));
            } else {
                // found element
                it->second ++;
            }
        }
        // Debug
        it = m.begin();
        for (it = m.begin(); it != m.end(); it++) {
            cout << "Word: " << it->first << " Freq: " <<  it->second << endl;
        }

        // Priority queue for top k selection
        priority_queue<pair<string, int>, vector<pair<string, int>>, comparator> q;

        for (pair<string, int> wordPair: m) {
            q.push(wordPair);
        }


        for (int i = 0; i < k; i++) {
            ret.push_back( q.top().first );
            q.pop();
        }

        reverse(ret.begin(), ret.end());
                
        return ret;
    }
};

int main() {
    int k = 4;
    vector<string> words = {"the","day","is","sunny","the","the","the","sunny","is","is"};

    Solution sol;
    vector<string> ret = sol.topKFrequent(words, k);

    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] << endl;
    }


}
