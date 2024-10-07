#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;


class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        string initial = "0000";
        if (initial==target) return 0;
        if (find(deadends.begin(), deadends.end(), initial)!=deadends.end()) return -1;
        int step = 0;
        queue<string> curQueue;
        unordered_set<string> visited;
        visited.insert(initial);
        curQueue.push(initial);
        while (!curQueue.empty()) {
            step++;
            int len = curQueue.size();
            for (int i=0;i<len;i++) {
                // cout << "curQueue.size(): " << curQueue.size() << endl;
                // cout << "step: " << step << endl;
                string curString = curQueue.front();
                curQueue.pop();
                // cout << "curString: " << curString << endl;
                vector<string> curNeighbors = getNeighbors(curString);
                // for (auto neighbor : curNeighbors) {
                //     cout << neighbor << endl;
                // }
                for (auto neighbor : curNeighbors) {
                    if (find(deadends.begin(), deadends.end(), neighbor)!=deadends.end()) continue;
                    if (neighbor==target) return step;
                    if (visited.find(neighbor)!=visited.end()) continue;
                    visited.insert(neighbor);
                    curQueue.push(neighbor);
                }
            }
        }
        return -1;

    }
private:
    vector<string> getNeighbors(string s) {
        vector<char> numDict = vector<char> {'9','0','1','2','3','4','5','6','7','8','9','0'};
        vector<string> neighbors;
        for (int i=0;i<4;i++){
            string n1 = s;
            n1[i] = numDict[s[i]-'0'];
            string n2 = s;
            n2[i] = numDict[s[i]-'0'+2];
            // cout << "n1: " << n1 << " n2: " << n2 << endl;
            neighbors.push_back(n1);
            neighbors.push_back(n2);
        }
        return neighbors;
    }
};

int main() {
    vector<string> deadends = {"0201","0101","0102","1212","2002"};
    string target = "0202";
    Solution sol;
    int res = sol.openLock(deadends, target);
    cout << res << endl;
    return 0;


}