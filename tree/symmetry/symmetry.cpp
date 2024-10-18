#include <vector>
#include <iostream>
using namespace std;
//  * Definition for a binary tree node.
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
    bool isSymmetric(TreeNode* root) {
        return naturalOrder(root->left) == reverseOrder(root->right);
    }
private:
    vector<int> naturalOrder(TreeNode* root) {
        if (!root) return {};
        vector<int> ans = naturalOrder(root->left);
        ans.push_back(root->val);
        vector<int> right = naturalOrder(root->right);
        ans.insert(ans.end(), right.begin(), right.end());
        return ans;
    }
    vector<int> reverseOrder(TreeNode* root) {
        if (!root) return {};
        vector<int> ans = reverseOrder(root->right);
        ans.push_back(root->val);
        vector<int> left = reverseOrder(root->left);
        ans.insert(ans.end(), left.begin(), left.end());
        return ans;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    Solution s;
    if (s.isSymmetric(root)) {
        cout << "Symmetric" << endl;
    }
    else {
        cout << "Not Symmetric" << endl;
    }
    return 0;
}