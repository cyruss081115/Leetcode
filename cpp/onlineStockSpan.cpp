#include <iostream>
#include <vector>

using namespace std;

class StockSpanner {
public:
    // <price, span>
    vector<pair<int, int>>record;

    int next(int price) {

      int ret = 1;
      int ptr = record.size() - 1;

      while (ptr >= 0 && price >= record[ptr].first) {
        ret += record[ptr].second;
        ptr -= record[ptr].second;
      }

      record.push_back(pair<int, int>(price, ret));
      return ret;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
int main() {
  StockSpanner* obj = new StockSpanner();
  cout << obj->next(100) << endl;
  cout << obj->next(80) << endl;
  cout << obj->next(60) << endl;
  cout << obj->next(70) << endl;
  cout << obj->next(60) << endl;
  cout << obj->next(75) << endl;
  cout << obj->next(85) << endl;
  
}
