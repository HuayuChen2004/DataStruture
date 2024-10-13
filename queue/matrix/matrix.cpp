#include <iostream>
#include <queue>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n, INT_MAX - 1)); // Use INT_MAX - 1 to avoid overflow
        queue<pair<int, int>> q;

        // Initialize the queue with all 0s and set their distance to 0 in the answer matrix
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    ans[i][j] = 0;
                }
            }
        }

        // Directions array for moving in 4 directions
        vector<vector<int>> dirs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        // BFS to update distances
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            for (const auto& dir : dirs) {
                int ni = i + dir[0], nj = j + dir[1];
                if (ni >= 0 && ni < m && nj >= 0 && nj < n && ans[ni][nj] == INT_MAX - 1) {
                    ans[ni][nj] = ans[i][j] + 1;
                    q.push({ni, nj});
                }
            }
        }

        return ans;
    }
};

int main() {
    vector<vector<int>> mat = {{0,0,0},{0,1,0},{1,1,1}};
    Solution s;
    vector<vector<int>> ans = s.updateMatrix(mat);
    for (const auto& row : ans) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}

/*
含queue的dp问题，这个题的思路是先把所有的0都加入queue，然后从0开始向四个方向扩散
*/