#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        // cout << "rooms.size(): " << rooms.size() << endl;
        vector<bool> accessible (rooms.size(), false);
        accessible[0] = true;
        stack<int> toBeExplored;
        for (int i=0;i<rooms[0].size();i++){
            // cout << "rooms[0][i]: " << rooms[0][i] << endl;
            toBeExplored.push(rooms[0][i]);
        }
        while (!toBeExplored.empty()){
            // cout << "toBeExplored top: " << toBeExplored.top() << endl;
            int currentRoom = toBeExplored.top();
            toBeExplored.pop();
            accessible[currentRoom]=true;
            if (!rooms[currentRoom].size()) continue;
            for (int room : rooms[currentRoom]) {
                if (!accessible[room]) {
                    toBeExplored.push(room);
                }
            }
        }
        for (int i=0;i<rooms.size();i++){
            if (!accessible[i]) return false;
        }
        return true;
    }
};

int main() {
    vector<vector<int>> rooms = {{1},{2},{3},{}};
    Solution s;
    // cout << "start" << endl;
    cout << s.canVisitAllRooms(rooms) << endl;
    return 0;
}