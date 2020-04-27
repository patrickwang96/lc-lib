#include "header.h"
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    inline bool hasNode(TreeNode* root, TreeNode* p) {
        if (root == nullptr) return false;
        if (root == p) return true;
        if (hasNode(root->left, p) || hasNode(root->right, p)) return true;
        return false;
    }
    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (hasNode(root->left, p) && hasNode(root->left, q))
            return solve(root->left, p, q);
        if (hasNode(root->right, p) && hasNode(root->right, q))
            return solve(root->right, p, q);
        return root;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root, p, q);
    }
};