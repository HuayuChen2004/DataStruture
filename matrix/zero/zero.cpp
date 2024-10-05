#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        unordered_set<int> zeroRows;
        unordered_set<int> zeroCols;
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (matrix[i][j]==0) {
                    zeroCols.insert(j);
                    zeroRows.insert(i);
                }
            }
        }
        for (int zeroRow : zeroRows) {
            for (int j=0;j<n;j++){
                matrix[zeroRow][j] = 0;
            }
        }
        for (int zeroCol : zeroCols) {
            for (int i=0;i<m;i++){
                matrix[i][zeroCol] = 0;
            }
        }
    }
};

int main() {
    vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};
    Solution sol;
    sol.setZeroes(matrix);
    for (auto row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;

}