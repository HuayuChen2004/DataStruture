#include <vector>
#include <string>
#include <stack>
#include <iostream>
using namespace std;




class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> stk;
        for (string token : tokens) {
            if (token=="+"||token=="-"||token=="*"||token=="/"){
                string s1 = stk.top();
                stk.pop();
                string s2 = stk.top();
                stk.pop();
                int i1 = stoi(s1);
                int i2 = stoi(s2);
                int res = 0;
                if (token=="+") res = i1 + i2;
                if (token=="-") res = i2 - i1;
                if (token=="*") res = i1 * i2;
                if (token=="/") res = i2 / i1;
                stk.push(to_string(res));
                // cout << "s1: " << s1 << " s2: " << s2 << " token: " << token << endl;
                // cout << "res: " << res << endl;
            }
            else {
                stk.push(token);
            }
        }
        return stoi(stk.top());
    }
};

int main() {
    vector<string> tokens = {"4","13","5","/","+"};
    Solution sol;
    cout << sol.evalRPN(tokens) << endl;
    return 0;
}