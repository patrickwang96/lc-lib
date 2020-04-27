#include "header.h"
// https://leetcode.com/problems/path-sum/
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
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == nullptr) return false;
        if (root->left == nullptr && root->right == nullptr) {
            // reached leaf
            return root->val == sum;
        }
        else {
            sum -= root->val;
            return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
        }
        
    }
};