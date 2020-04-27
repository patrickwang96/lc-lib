#include "header.h"
// https://leetcode.com/problems/symmetric-tree/
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
    bool checkSubTree(TreeNode* a, TreeNode*b) {
        if (a == NULL && b == NULL) {
            return true;
        }
        if (a == NULL || b == NULL) {
            return false;
        }
        if (a->val == b->val) {
            return checkSubTree(a->left, b->right) && checkSubTree(a->right, b->left);
        }
        else 
            return false;
    }
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) 
            return true;
        return checkSubTree(root->left, root->right);
        
        
    }
};