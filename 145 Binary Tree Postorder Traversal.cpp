#include "header.h"
// https://leetcode.com/problems/binary-tree-postorder-traversal/
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root != NULL) {
            if (root->left != NULL) {
                vector<int> leftResult = postorderTraversal(root->left);
                result.insert(result.end(), leftResult.begin(), leftResult.end());
            }
            if (root->right != NULL) {
                vector<int> rightResult = postorderTraversal(root->right);
                result.insert(result.end(), rightResult.begin(), rightResult.end());
            }
            
            
            result.push_back(root->val);
        }
        return result;
        
    }
};