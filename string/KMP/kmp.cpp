#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int len = needle.size();
        vector<int> next = getNext(needle, len);
        // cout << "next: " << endl;
        // for (int i=0;i<len;i++) cout << next[i] << " ";
        // cout << endl;
        int i=0,j=0;
        while (i<haystack.size()) {
            while (haystack[i]==needle[j] && j<len) {
                i++;
                j++;
            }
            // cout << "i: " << i << " j: " << j << endl;
            if (j==len) return i-len;
            if (j==0) i++;
            else j=next[j];

        }
        return -1;
    }
private:
    vector<int> getNext(string p, int len) {
        vector<int> next(len, -1);
        int i=0,j=-1;
        while (i<len-1) {
            if (j==-1 || p[j]==p[i]) {
                j++;
                i++;
                next[i]=j;
            }
            else j = next[j];
        }
        return next;
    }
};

int main() {
    string haystack = "a";
    string needle = "a";
    Solution sol;
    int res = sol.strStr(haystack, needle);
    cout << res << endl;
    return 0;
}
