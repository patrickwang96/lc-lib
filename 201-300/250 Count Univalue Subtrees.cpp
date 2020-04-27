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
    bool isUniTree(TreeNode* root) {
        if (root == NULL) {
            return false;
        }
        if (root->left == NULL && root->right == NULL) {
            return true;
        }
        bool result = false;
        if (root->left) {
            if (root->left->val != root->val || !isUniTree(root->left))
                return false;
        }
        if (root->right) {
            if (root->right->val != root->val || !isUniTree(root->right)) 
                return false;
        }
        return true;
    }
public:
    int countUnivalSubtrees(TreeNode* root) {
        if (root == NULL) 
            return 0;
        if (root->left == NULL & root->right == NULL)
            return 1;
        if (isUniTree(root)) {
            return countUnivalSubtrees(root->left) + countUnivalSubtrees(root->right) + 1;
        }
        else {
            return countUnivalSubtrees(root->left) + countUnivalSubtrees(root->right);
        }
        
    }
};