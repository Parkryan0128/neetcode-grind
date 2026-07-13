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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return nullptr;
        }

        if (root->val == p->val) {
            if (searchNode(root->left, q->val) || searchNode(root->right, q->val)) {
                return root;
            }
        }

        if (root->val == q->val) {
            if (searchNode(root->left, p->val) || searchNode(root->right, p->val)) {
                return root;
            }
        }

        bool left_one = searchNode(root->left, p->val);
        bool left_two = searchNode(root->left, q->val);

        if (left_one != left_two) {
            return root;
        }

        if (left_one) {
            return lowestCommonAncestor(root->left,p,q);
        } 

        return lowestCommonAncestor(root->right,p,q);
    }

private:
    bool searchNode(TreeNode* node, int val) {
        if (node == nullptr) return false;
        if (node->val == val) return true;
        return searchNode(node->left, val) || searchNode(node->right, val);
    }
};
