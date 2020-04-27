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
    bool solve(TreeNode* root, int val) {
        if (!root) return true;
        if (root->val != val) return false;
        return solve(root->left, val) && solve(root->right, val);
    }
public:
    bool isUnivalTree(TreeNode* root) {
        int val = root->val;
        return solve(root, val);
    }
};