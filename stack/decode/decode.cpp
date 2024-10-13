#include <iostream>
#include <stack>
#include <string>

using namespace std;


class Solution {
public:
    string decodeString(string s) {
        string decodedString = "";
        int i=0;
        while (i < s.size()) {
            if (s[i]-'0' >= 1 && s[i]-'0'<=9) {
                decodedString+=decodeOnce(s, i);
                // stack<char> stk;
                // stk.push('[');
                // i++;
                // while (!stk.empty()) {
                //     i++;
                //     // cout << "s[i]: " << s[i] << endl;
                //     if (s[i]=='[') stk.push('[');
                //     if (s[i]==']') stk.pop();
                // }
                i++;
                // cout << "stk size: " << stk.size() << endl;
                cout << "i: " << i << endl;
            }
            else {
                decodedString+=s[i++];
            }
            cout << "i: " << i << endl;
        }
        return decodedString;
    }
private:
    string decodeOnce(string s, int& start) {
        string numString = "";
        while (s[start]-'0' >= 0 && s[start]-'0'<=9) {
            numString+=s[start];
            start++;
        }
        int repeatNum = stoi(numString);
        start+=1;
        string repeatString = "";
        while (s[start]!=']') {
            if (s[start]-'0' >= 1 && s[start]-'0'<=9) {
                repeatString+=decodeOnce(s, start);
                // stack<char> stk;
                // stk.push('[');
                // start++;
                // while (!stk.empty()) {
                //     start++;
                //     if (s[start]=='[') stk.push('[');
                //     if (s[start]==']') stk.pop();
                // }
            }
            else repeatString+=s[start];
            start++;
        }
        string res = "";
        for (int i=0;i<repeatNum;i++){
            res+=repeatString;
        }
        return res;
    }
};

int main() {
    string inputString = "100[leetcode]";
    Solution s;
    cout << s.decodeString(inputString) << endl;
    return 0;
}