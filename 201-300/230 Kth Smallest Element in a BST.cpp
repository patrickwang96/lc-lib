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
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        else return (countNodes(root->left) + countNodes(root->right) + 1);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int a = countNodes(root->left);
        if (a >= k) return kthSmallest(root->left, k);
        else if (a + 1 == k) return root->val;
        else return kthSmallest(root->right, k - a - 1);
        
    }
};