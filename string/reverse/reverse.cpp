#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        int pointer = s.size()-1;
        while (pointer>=0) {
            while (pointer>=0 && s[pointer]==' ') pointer--;
            if (pointer<0) break;
            string current = "";
            while (pointer>= 0 && s[pointer]!=' ') {
                current.insert(0, 1, s[pointer]);
                pointer--;
            }
            // cout << "pointer: " << pointer << endl;
            // cout << "current: " << current << endl;
            res += current;
            res += " ";
        }
        res.pop_back();
        return res;
    }
};

int main() {
    string s = "the sky is blue";
    Solution sol;
    string res = sol.reverseWords(s);
    cout << res << endl;
    return 0;
}