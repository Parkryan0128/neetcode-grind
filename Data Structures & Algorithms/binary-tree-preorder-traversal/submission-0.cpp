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
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> my_stack;
        TreeNode* curr = root;

        while (curr || !my_stack.empty()) {
            if (curr) {
                res.push_back(curr->val);
                my_stack.push(curr->right);
                curr = curr->left;
            } else {
                curr = my_stack.top();
                my_stack.pop();
            }
        }

        return res;
    }
};