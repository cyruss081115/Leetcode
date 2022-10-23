#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        string intToRoman(int num) {
            string ret;
            int numCpy = num;

            string gor[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
            string ten[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
            string hun[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
            string thu[] = {"", "M", "MM", "MMM"};


            ret.append(thu[numCpy/1000]);
            numCpy = numCpy - 1000 * (numCpy/1000);

            ret.append(hun[numCpy / 100]);
            numCpy = numCpy - 100 * (numCpy/100);

            ret.append(ten[numCpy / 10]);
            numCpy = numCpy - 10 * (numCpy/10);

            ret.append(gor[numCpy]);
            
            return ret;
        }
};

int main () {
    int num = 58;
    Solution sol;
    cout << sol.intToRoman(num) << endl;
    
}
