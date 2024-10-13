#include <iostream>
#include <vector>
#include <stack>
using namespace std;


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        if (temperatures.empty()) return {};
        if (temperatures.size()==1) return {0};
        // if sorted in descending order return all 0s
        bool sorted = true;
        for (int i=1;i<temperatures.size();i++){
            if (temperatures[i]>temperatures[i-1]){
                sorted = false;
                break;
            }
        }
        if (sorted) return vector<int>(temperatures.size(), 0);
        stack<int> curStack;
        vector<int> res(temperatures.size(), 0);
        vector<int> curIndex;
        curStack.push(temperatures[0]);
        curIndex.push_back(0);
        for (int i=1;i<temperatures.size();i++){
            for (int index : curIndex) {
                res[index]++;
            }
            while (curStack.size() && temperatures[i]>curStack.top()){
                curStack.pop();
                curIndex.pop_back();
            }
            curStack.push(temperatures[i]);
            curIndex.push_back(i);
        }
        curIndex.pop_back();
        for (int index : curIndex) {
            res[index]=0;
        }
        return res;
    }
};

int main() {
    vector<int> temperatures(100000, 30);
    Solution sol;
    vector<int> res = sol.dailyTemperatures(temperatures);
    for (int i=0;i<res.size();i++){
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;

}