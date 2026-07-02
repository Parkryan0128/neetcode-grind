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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> my_stack;
        TreeNode* curr = root;

        while (curr || !my_stack.empty()) {
            while (curr) {
                my_stack.push(curr);
                curr = curr->left;
            }

            curr = my_stack.top();
            my_stack.pop();
            res.push_back(curr->val);
            curr = curr->right;
        }


        return res;
    }
};