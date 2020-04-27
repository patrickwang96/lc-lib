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
    int solve(TreeNode* root, int &counter) {
        if (root == nullptr) return 0;
        int l = solve(root->left, counter);
        int r = solve(root->right, counter);
        
        counter += abs(l) + abs(r);
        return root->val + l + r -1;
        
    }
public:
    int distributeCoins(TreeNode* root) {
        int ret = 0;
        solve(root, ret);
        return ret;
    }
};