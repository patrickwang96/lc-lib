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
    int s(TreeNode* root, int l, int r) {
        if (root == nullptr) return 0;
        if (root->val < l) return s(root->right, l, r);
        if (root->val > r) return s(root->left, l, r);
        
        return s(root->right, l, r) + s(root->left, l, r) + root->val;
    }
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        return s(root, L, R);
        
    }
};