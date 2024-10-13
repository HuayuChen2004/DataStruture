#include <iostream>
#include <stack>
#include <string>
#include <vector>   

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> answer;
        stack<TreeNode*> stk;
        TreeNode* currentNode = root;
        while (!stk.empty() || currentNode != nullptr) {
            // cout << "currentNode: " << currentNode->val << endl;
            // cout << "stack size: " << stk.size() << endl;
            if (!currentNode) {
                // cout << "stk top: " << stk.top()->val << endl;
                currentNode = stk.top();
                stk.pop();
                answer.push_back(currentNode->val);
                currentNode = currentNode->right;
            }
            // cout << "currentNode: " << currentNode->val << endl;
            while(currentNode) {
                stk.push(currentNode);
                currentNode = currentNode->left;
            }
        }
        return answer;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    Solution s;
    vector<int> ans = s.inorderTraversal(root);
    for (int val : ans) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}

/*
这个题本质上是进入了stack里面的节点都是没有左节点的了，
所以中序遍历只需要加入当前节点的值，然后把节点赋为当前节点的右节点




*/