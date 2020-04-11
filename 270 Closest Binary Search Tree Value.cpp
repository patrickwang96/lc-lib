#include "header.h"
// https://leetcode.com/problems/closest-binary-search-tree-value/
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
    int closestValue(TreeNode* root, double target) {
        if (target == root->val) return root->val;
        else if (target < root->val) {
            // compare with left substree
            if (root->left == nullptr) return root->val;
            double d1 = root->val - target;
            int l = closestValue(root->left, target);
            double d2 = abs(l - target);
            if (d1 < d2) return root->val;
            else return l;
        } else {
            // compare with right
            if (root->right == nullptr) return root->val;
            double d1 = target - root->val ;
            int r = closestValue(root->right, target);
            double d2 = abs(r - target);
            if (d1 < d2) return root->val;
            else return r;
        }
        
    }
};