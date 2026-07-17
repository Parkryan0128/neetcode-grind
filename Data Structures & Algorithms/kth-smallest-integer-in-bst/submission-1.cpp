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
    std::vector<int> ordered_list;

    int kthSmallest(TreeNode* root, int k) {
        dfs(root);
        return ordered_list[k-1];
    }

private:
    void dfs(TreeNode* node) {
        if (node == nullptr) return;

        dfs(node->left);
        ordered_list.push_back(node->val);
        dfs(node->right);

        return;
    }
};
