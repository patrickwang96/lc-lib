#include "header.h"
// https://leetcode.com/problems/binary-tree-inorder-traversal/
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> buffer;
        if (root == nullptr) return result;
        
        TreeNode* ptr = root->left;
        buffer.push(root);
        while (ptr != nullptr) {
            buffer.push(ptr);
            ptr = ptr->left;
        }
        while (!buffer.empty()) {
            ptr = buffer.top();
            buffer.pop();
            result.push_back(ptr->val);
            if (ptr->right) {
                buffer.push(ptr->right);
                ptr = ptr->right->left;
                while (ptr != nullptr) {
                    buffer.push(ptr);
                    ptr = ptr->left;
                }
            }
        }
        return result;
    }
};