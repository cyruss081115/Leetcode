#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int prevElement;
        int bound = min(m, n);
        
        for (int i = 0; i < n; i++) {
            prevElement = matrix[0][i];
            for (int j = 0; j < m && i + j < n; j++) {
                cout << "Checking i: " << i << " j: " << j << endl;
                if (prevElement != matrix[j][i+j]) 
                    return false;
                prevElement = matrix[j][i+j];
            }
        }
        
        for (int i = 1; i < m; i++) {
            prevElement = matrix[i][0];
            for (int j = 0; j < n && i + j < m; j++) {
                cout << "Checking i: " << i << " j: " << j << endl;
                if (prevElement != matrix[i+j][j]){
                    return false;
                }
                prevElement = matrix[i+j][j];
            }
        }
        
        return true;
    }
};

int main() {
    vector<vector<int>> matrix = {{83}, {64}, {57}};
    Solution sol;
    cout << (sol.isToeplitzMatrix(matrix) ? "true": "false") << endl;
}
