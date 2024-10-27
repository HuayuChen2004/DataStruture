#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

// operator hierarchy
int operatorHierarchy(char op) {
    if (op=='+' || op=='-') return 1;
    else if (op=='*' || op=='/') return 2;
    else return 0;
}

string suffix(string midFixString) {
    stack<char> operatorStack;
    stack<char> ansStack;
    for (int i=0;i<midFixString.size();i++){
        if (midFixString[i]-'0'>=0 && midFixString[i]-'0'<=9 || midFixString[i]>='a' && midFixString[i]<='z') {
            char c = midFixString[i];
            ansStack.push(c);
        }
        else if (midFixString[i]=='(') {
            char c = midFixString[i];
            operatorStack.push(c);
        }
        else if (midFixString[i]==')') {
            char op = operatorStack.top();
            while ( op != '(') {
                operatorStack.pop();
                ansStack.push(op);
                op = operatorStack.top();
            }
            operatorStack.pop();
        }
        else {
            char c = midFixString[i];
            if (operatorStack.empty() || operatorStack.top()=='(' ) operatorStack.push(c);
            else if (operatorHierarchy(midFixString[i])>operatorHierarchy(operatorStack.top())) {
                operatorStack.push(c);
            }
            else {
                ansStack.push(operatorStack.top());
                operatorStack.pop();
                i--;
            }
        }
    }
    while (!operatorStack.empty()) {
        ansStack.push(operatorStack.top());
        operatorStack.pop();
    }
    string ans = "";
    while (!ansStack.empty()) {
        operatorStack.push(ansStack.top());
        ansStack.pop();
    }
    while (!operatorStack.empty()) {
        ans += operatorStack.top();
        operatorStack.pop();
    }
    return ans;
}

int main() {
    string midFixString = "(a+b)*c-d/(e-f)*g+h";
    cout << suffix(midFixString) << endl;
    return 0;
}