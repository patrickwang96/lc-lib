#include "header.h"
// https://leetcode.com/problems/binary-tree-preorder-traversal/
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root != NULL) {
            result.push_back(root->val); 
            if (root->left != NULL) {
            vector<int> leftResult = preorderTraversal(root->left);
            result.insert(result.end(), leftResult.begin(), leftResult.end());
        }
            if (root->right != NULL) {
                vector<int> rightResult = preorderTraversal(root->right);
                result.insert(result.end(), rightResult.begin(), rightResult.end());
            }
        }
        
        return result;
    }
    
};