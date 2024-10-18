#include <iostream>
#include <vector>

using namespace std;


// Definition for a binary tree node.
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        vector<int> sums = dfs(root);
        for (int sum:sums) {
            // cout << "sum: " << sum << endl;
            if (sum == targetSum) return true;
        }
        return false;
    }
private:
    vector<int> dfs(TreeNode* root) {
        if (!root) return {};
        // cout << "root: " << root->val << endl;
        vector<int> left = dfs(root->left);
        vector<int> right = dfs(root->right);
        if (!left.size() && !right.size()) {
            return {root->val};
        }
        if (!left.size()) {
            for (int i = 0; i < right.size(); i++) {
                right[i] += root->val;
            }
            return right;
        }
        if (!right.size()) {
            for (int i = 0; i < left.size(); i++) {
                left[i] += root->val;
            }
            return left;
        }
        vector<int> ans;
        for (int i = 0; i < left.size(); i++) {
            ans.push_back(left[i] + root->val);
        }
        for (int i = 0; i < right.size(); i++) {
            ans.push_back(right[i] + root->val);
        }
        return ans;
    }
};

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);
    Solution s;
    if (s.hasPathSum(root, 22)) {
        cout << "Has Path Sum" << endl;
    }
    else {
        cout << "No Path Sum" << endl;
    }
    return 0;
}