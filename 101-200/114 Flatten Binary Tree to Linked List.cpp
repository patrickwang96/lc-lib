#include "header.h"
// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
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
    TreeNode* flat(TreeNode* root) {
        if (root == nullptr) return root;
        if (root->left == nullptr) {
            if (root->right == nullptr) return root;
            else return flat(root->right);
        } else {
            if (root->right == nullptr) {
                root->right = root->left;
                root->left = nullptr;
                return flat(root->right);
            } else {
                TreeNode* right = root->right;
                root->right = root->left;
                root->left = nullptr;
                TreeNode* cur = flat(root->right);
                cur->right = right;
                return flat(cur->right);
            }
        }
    }
public:
    void flatten(TreeNode* root) {
        flat(root);
    }
};