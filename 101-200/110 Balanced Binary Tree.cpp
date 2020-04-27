#include "header.h"
// https://leetcode.com/problems/balanced-binary-tree/
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
    int d(TreeNode* root) {
        if (!root) return 0;
        else return max(d(root->left), d(root->right)) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        
        if (!root) return true;
        return (abs(d(root->left) - d(root->right)) <= 1) && isBalanced(root->right) && isBalanced(root->left);
        
    }
};