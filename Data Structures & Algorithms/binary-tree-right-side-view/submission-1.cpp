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
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return {};
        vector<int> res;
        std::queue<TreeNode*> my_q;
        my_q.push(root);

        while (!my_q.empty()) {
            int size = my_q.size();
            TreeNode* item;
            for (int i=0; i < size; i++) {
                item = my_q.front();
                if (item->left != nullptr) my_q.push(item->left);
                if (item->right != nullptr) my_q.push(item->right);
                my_q.pop();
            }

            res.push_back(item->val);
        }

        return res;
    }
};
