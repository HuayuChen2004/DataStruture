#include <iostream>
#include <vector>
#include <queue>
using namespace std;


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int sum = 0;
        int rows = grid.size();
        if (rows == 0) return 0;
        int cols = grid[0].size();
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == '1') {
                    bfs(grid, i, j, rows, cols);
                    sum++;
                }
            }
        }
        return sum;
    }
private:
    void bfs(vector<vector<char>>& grid, int row, int col, int rows, int cols) {
        queue<pair<int, int>> cur;
        cur.push({row, col});
        while (!cur.empty()) {
            auto [curRow, curCol] = cur.front();
            cur.pop();
            grid[curRow][curCol] = '0';
            if (curRow > 0 && grid[curRow - 1][curCol] == '1') cur.push({curRow - 1, curCol});
            if (curRow < rows - 1 && grid[curRow + 1][curCol] == '1') cur.push({curRow + 1, curCol});
            if (curCol > 0 && grid[curRow][curCol - 1] == '1') cur.push({curRow, curCol - 1});
            if (curCol < cols - 1 && grid[curRow][curCol + 1] == '1') cur.push({curRow, curCol + 1});
        }
    }
};


int main() {
    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    Solution sol;
    int res = sol.numIslands(grid);
    cout << res << endl;
    return 0;

}