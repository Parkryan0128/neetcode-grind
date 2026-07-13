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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) return new TreeNode(val);
        insert(root,val);
        return root;
    }

private:
    void insert(TreeNode* root, int val) {
        if (root == nullptr) return;

        if (root->left && root->val > val) {
            return insert(root->left, val);
        }

        if (root->right && root->val < val) {
            return insert(root->right,val);
        }

        if (root->val > val) {
            root->left = new TreeNode(val);
        } else {
            root->right = new TreeNode(val);
        }
    }
};