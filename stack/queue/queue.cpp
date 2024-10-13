#include <iostream>
#include <stack>
using namespace std;


class MyQueue {
private:
    stack<int> back;
    stack<int> backCopy;
public:
    MyQueue() {

    }
    
    void push(int x) {
        back.push(x);
        backCopy.push(x);
    }
    
    int pop() {
        int n = backCopy.size();
        for (int i=0;i<n-1;i++){
            back.push(backCopy.top());
            backCopy.pop();
        }
        backCopy.pop();
        for (int i=0;i<n-1;i++){
            backCopy.push(back.top());
            back.pop();
        }
        for (int i=0;i<n-1;i++){
            backCopy.push(back.top());
            back.pop();
        }
        int res = back.top();
        back.pop();
        for (int i=0;i<n-1;i++){
            back.push(backCopy.top());
            backCopy.pop();
        }
        return res;
    }
    
    int peek() {
        int n = backCopy.size();
        for (int i=0;i<n-1;i++){
            back.push(backCopy.top());
            backCopy.pop();
        }
        int res = backCopy.top();
        for (int i=0;i<n-1;i++){
            backCopy.push(back.top());
            back.pop();
        }
        return res;
    }
    
    bool empty() {
        // cout << "back: " << endl;
        // cout << "back size: " << back.size() << endl;
        // cout << "back top: " << back.top() << endl;
        // for (int i=0;i<back.size();i++){
        //     cout << "back top: " << back.top() << endl;
        //     back.pop();
        // }
        // cout << endl;
        // cout << "backCopy: " << endl;
        // cout << "backCopy size: " << backCopy.size() << endl;
        // cout << "backCopy top: " << backCopy.top() << endl;
        
        // for (int i=0;i<backCopy.size();i++){
        //     cout << "backCopy top: " << backCopy.top() << endl;
        //     backCopy.pop();
        // }
        // cout << endl;
        return back.empty()||backCopy.empty();
    }
};

int main() {
    MyQueue q;
    q.push(1);
    q.push(2);
    cout << q.peek() << endl;
    cout << q.pop() << endl;
    cout << q.empty() << endl;
    return 0;
}
