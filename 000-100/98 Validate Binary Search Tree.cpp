#include "header.h"
// https://leetcode.com/problems/validate-binary-search-tree/
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
    bool check(TreeNode* root, long long upper, long long lower) {
        if (root == nullptr) return true;
        if (root->val <= lower) return false;
        if (root->val >= upper) return false;
        
        if (check(root->left, root->val, lower) && check(root->right, upper, root->val)) return true;
        else return false;
    }
public:
    bool isValidBST(TreeNode* root) {
        return check(root, LLONG_MAX, LLONG_MIN);
    }
};