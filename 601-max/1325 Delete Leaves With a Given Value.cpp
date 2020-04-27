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
    inline bool isTarget(TreeNode* root, int target) {
        if (!root) return false;
        if (!root->left && !root->right && root->val == target) return true;
        return false;
    }
    
    void trim(TreeNode* root, int target) {
        if(!root) return ;
        trim(root->left, target);
        trim(root->right, target);
        if (isTarget(root->left, target)) root->left = nullptr;
        if (isTarget(root->right, target)) root->right = nullptr;
        return ;
    }
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        trim(root, target);
        if (isTarget(root, target)) return nullptr;
        return root;
    }
};