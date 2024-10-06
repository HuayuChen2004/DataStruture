#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res (rowIndex+1, 1);
        if (rowIndex<2) return res;
        for (int i=1;i<rowIndex;i++){
            vector<int> pre = res;
            // for (int j=0;j<pre.size();j++){
            //     cout << pre[j] << " ";
            // }
            // cout << endl;
            for (int j=1;j<=i;j++){
                res[j]=pre[j-1]+pre[j];
            }
        }
        return res;
    }
};

int main() {
    int rowIndex = 2;
    Solution sol;
    vector<int> res = sol.getRow(rowIndex);
    for (int i=0;i<res.size();i++){
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}