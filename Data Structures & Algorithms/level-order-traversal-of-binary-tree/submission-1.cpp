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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        std::queue<TreeNode*> my_q;
        std::vector<vector<int>> res;
        my_q.push(root);

        while (!my_q.empty()) {
            int items = my_q.size();
            std::vector<int> level;

            for (int i=0; i<items; i++) {
                TreeNode* item = my_q.front();
                if (item->left != nullptr) my_q.push(item->left);
                if (item->right != nullptr) my_q.push(item->right);
                level.push_back(item->val);
                my_q.pop();
            }

            res.push_back(level);
        }

        return res;
    }
};
