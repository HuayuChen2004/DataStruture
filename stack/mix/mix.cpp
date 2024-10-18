#include <iostream>
#include <stack>
#include <vector>

using namespace std;


bool IsMix(vector<int> order) {
    int n = order.size();
    stack<int> stk;
    int rightOrderIdx = 1;
    // vector<int> rightOrder;
    for (int i=0;i<n;i++){
        if (rightOrderIdx==n+1) {
            if (stk.top()==order[i]) {
                // cout << "pop " << stk.top() << endl;
                // cout << "order " << order[i] << endl;
                cout << "pop " << stk.top() << endl;
                stk.pop();
                continue;
            }
            else return false;
        }
        else {
            while(stk.empty() || stk.top()!=order[i]) {
                stk.push(rightOrderIdx++);
                cout << "push " << stk.top() << endl;
            }
            cout << "pop " << stk.top() << endl;
            stk.pop();
        }
    }
    // cout << "stk size " << stk.size() << endl;
    // cout << "stk top " << stk.top() << endl;
    return stk.empty();

}

int main() {
    vector<int> order = {4, 5, 3, 2, 1};
    cout << IsMix(order) << endl;
    return 0;
}