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
    bool contain1(TreeNode* root) {
        if (root == nullptr) return false;
        if (root->val == 1) return true;
        if (contain1(root->left) || contain1(root->right)) return true;
        return false;
    }
public:
    TreeNode* pruneTree(TreeNode* root) {
        if (!contain1(root)) return nullptr;
        // if (!contain1(root->left)) root->left = nullptr;
        // if (!contain1(root->right)) root->right = nullptr;
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        return root;
    }
};