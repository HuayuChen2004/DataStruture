#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> res;
        for (int i=0;i<m+n;i++){
            if (i & 1) {
                if (i < n) {
                    for (int j=0; j<=i && j<m; j++){
                        res.push_back(mat[j][i-j]);
                    }
                }
                else {
                    for (int j=0;j<m+n-i-1 && j<=n-1;j++){
                        res.push_back(mat[i-n+j+1][n-1-j]);
                    }
                }
            }
            else {
                if (i < m) {
                    for (int j=0; j<=i && j<n; j++){
                        res.push_back(mat[i-j][j]);
                    }
                }
                else {
                    for (int j=0;j<m+n-i-1 && j<=m-1;j++){
                        res.push_back(mat[m-1-j][i-m+j+1]);
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    Solution sol;
    vector<int> res = sol.findDiagonalOrder(matrix);
    for (int row = 0; row < matrix.size(); row++) {
        for (int val : matrix[row]) {
            cout << val << " ";
        }
        cout << endl;
    }
    cout << "Diagonal order: ";
    for (int val : res) {
        cout << val << " ";
    }
    cout << endl;
    return 0;

}