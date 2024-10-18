#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<char> digitChar = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

string digitTransform(string originalString, int originalBase, int newBase) {
    int decimal = 0;
    int power = 0;
    if (originalBase!=10) {
        for (int i=originalString.size()-1;i>=0;i--) {
            auto it = find(digitChar.begin(), digitChar.end(), originalString[i]);
            int decimalNum = distance(digitChar.begin(), it);
            decimal+=decimalNum*pow(originalBase, power);
            power++;
        }
    }
    else {
        decimal = stoi(originalString);
    }
    cout << "decimal " << decimal << endl;
    stack<char> stk;
    while (decimal!=0) {
        int remainder = decimal % newBase;
        stk.push(digitChar[remainder]);
        decimal /= newBase;
    }
    string ans = "";
    while (stk.size()) {
        ans += stk.top();
        stk.pop();
    }
    return ans;
}

int main() {
    string originalString = "10DE22";
    int originalBase = 16;
    int newBase = 5;
    cout << digitTransform(originalString, originalBase, newBase) << endl;
    return 0;
}