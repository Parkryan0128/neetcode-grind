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
    int goodNodes(TreeNode* root) {
        std::stack<pair<TreeNode*,int>> my_stack;
        int res = 0;
        my_stack.push({root, root->val});

        while (!my_stack.empty()) {
            auto [current_node, current_max] = my_stack.top();
            my_stack.pop();
            if (current_node->val >= current_max) {
                res++;
            }

            int next_max = max(current_max, current_node->val);

            if (current_node->right) {
                my_stack.push({current_node->right, next_max});
            }

            if (current_node->left) {
                my_stack.push({current_node->left, next_max});
            }
        }

        return res;
    }
};
