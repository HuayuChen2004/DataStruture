#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for (int i=1;i<=numRows;i++){
            vector<int> cur(i, 1);
            if (i>=3) {
                for (int j=1;j<i-1;j++){
                    // cout << "i: " << i << " j: " << j << endl;
                    cur[j]=res[i-2][j-1]+res[i-2][j];
                }
            }
            res.push_back(cur);
        }
        return res;
    }
};

int main() {
    int numRows = 5;
    Solution sol;
    vector<vector<int>> res = sol.generate(numRows);
    for (int i=0;i<res.size();i++){
        for (int j=0;j<res[i].size();j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
