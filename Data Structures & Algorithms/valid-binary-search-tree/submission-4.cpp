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
    bool isValidBST(TreeNode* root) {
        std::stack<tuple<TreeNode*, int, int>> my_stack;
        my_stack.push({root, INT_MIN, INT_MAX});

        while (!my_stack.empty()) {
            auto [curr_node, left, right] = my_stack.top();
            my_stack.pop();

            if (!(left < curr_node->val && curr_node->val < right)) {
                return false;
            }

            if (curr_node->left) {
                my_stack.push({curr_node->left, left, curr_node->val});
            }

            if (curr_node->right) {
                my_stack.push({curr_node->right, curr_node->val, right});
            }
        }

        return true;
    }
};
