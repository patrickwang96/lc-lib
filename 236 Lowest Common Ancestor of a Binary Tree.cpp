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
    bool hasNode(TreeNode* root, TreeNode* p) {
        if (root == NULL) {
            return false;
        }
        if (root == p) {
            return true;
        }
        else {
            return hasNode(root->left, p) || hasNode(root->right, p);
        }
    }
    
    bool hasLCA(TreeNode* root, TreeNode* p, TreeNode* q) {
        return hasNode(root, p) && hasNode(root, q);
    }
    
    
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (hasLCA(root->left, p, q)) {
            return lowestCommonAncestor(root->left, p, q);
        }
        if (hasLCA(root->right, p, q)) {
            return lowestCommonAncestor(root->right, p, q);
        }
        
        return root;
        
        
    }
};