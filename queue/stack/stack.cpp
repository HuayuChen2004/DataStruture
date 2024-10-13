#include <iostream>
#include <queue>

using namespace std;

class MyStack {
private:
    queue<int> q;
public:
    MyStack() {

    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        int len = q.size();
        for (int i=0;i<len-1;i++){
            q.push(q.front());
            q.pop();
        }
        int res = q.front();
        q.pop();
        return res;
    }
    
    int top() {
        int len = q.size();
        for (int i=0;i<len-1;i++){
            q.push(q.front());
            q.pop();
        }
        int res = q.front();  
        q.push(q.front());  
        // cout << "after top(): " << endl;
        // for (int i=0;i<q.size();i++){
        //     cout << "q.front() = " << q.front() << " ";
        //     q.pop();
        // }
        // cout << endl;
        q.pop();
        return res;
    }
    
    bool empty() {
        // if (!q.empty()) {
        //     for (int i=0;i<q.size();i++){
                // cout << "q.front() = " << q.front() << " ";
        //         q.pop();
        //     }
        //     cout << endl;
        // }
        return q.empty();
    }
};

int main() {
    MyStack obj = MyStack();
    obj.push(1);
    obj.push(2);
    cout << obj.top() << endl;
    cout << obj.pop() << endl;
    cout << obj.pop() << endl;
    cout << obj.empty() << endl;
    
    return 0;
}