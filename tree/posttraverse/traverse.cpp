/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// class Solution {
// public:
//     vector<int> postorderTraversal(TreeNode* root) {
//         if (!root) return {};
//         vector<int> ans;
//         stack<TreeNode*> leftStack;
//         stack<TreeNode*> rightStack;
//         TreeNode* ansBackNode;
//         leftStack.push(root);
//         while (!leftStack.empty() || !rightStack.empty()) {
//             while (!leftStack.empty()) {
//                 TreeNode* currentNode = leftStack.top();
//                 leftStack.pop();
//                 if (currentNode->left==nullptr && currentNode->right==nullptr) {
//                     ans.push_back(currentNode->val);
//                     ansBackNode = currentNode;
//                 }
//                 else if (ans.size()>0 && currentNode->right!=nullptr && currentNode->right==ansBackNode) {
//                     ans.push_back(currentNode->val);
//                     ansBackNode = currentNode;
//                 }
//                 else if (currentNode->right==nullptr && ans.size()>0 && currentNode->left!=nullptr && ansBackNode==currentNode->left) {
//                     ans.push_back(currentNode->val);
//                     ansBackNode = currentNode;
//                 }
//                 else {
//                     rightStack.push(currentNode);
//                     if (currentNode->left!=nullptr) leftStack.push(currentNode->left);
//                     if (currentNode->right!=nullptr) rightStack.push(currentNode->right);
//                 }
//             }
//             if (rightStack.size()) {
//                 TreeNode* t = rightStack.top();
//                 rightStack.pop();
//                 leftStack.push(t);
//             }
//         }
//         return ans;
//     }
// };

//双栈法，这个也适用于中序遍历