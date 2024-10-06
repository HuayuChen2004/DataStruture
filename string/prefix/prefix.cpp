#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs[0].size()==0) return "";
        string commonPrefix = "";
        int index = 0;
        int numStr = strs.size();
        bool flag = true;
        while (flag) {
            char c = strs[0][index];
            for (int i=1;i<numStr;i++){
                if (index >= strs[i].size()) flag=false;
                if (strs[i][index]!=c) flag=false;
            }
            if (!flag) break;
            commonPrefix += c;
            index++;
            if (index >= strs[0].size()) break;
        }
        return commonPrefix;
    }
};

int main() {
    vector<string> strs = {"flower","flow","flight"};
    Solution sol;
    string res = sol.longestCommonPrefix(strs);
    cout << res << endl;
    return 0;


}
