#include "header.h"
// https://leetcode.com/problems/diameter-of-binary-tree/
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
    int depth(TreeNode* root) {
        if (root == nullptr) return 0;
        return max(depth(root->left), depth(root->right)) + 1;
    }
    int solve(TreeNode* root) {
        if (root == nullptr) return 0;
        int left = solve(root->left);
        int right = solve(root->right);
        
        int cur = depth(root->left) + depth(root->right);
        return max(max(left, right), cur);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return solve(root);
    }
};