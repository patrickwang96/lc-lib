#include "header.h"
// https://leetcode.com/problems/balance-a-binary-search-tree/
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
    void travel(vector<TreeNode*>& nodes, TreeNode* root) {
        if (root== nullptr) return ;
        travel(nodes, root->left);
        nodes.push_back(root);
        travel(nodes, root->right);
    }
    
    TreeNode* constructBalanceTree(vector<TreeNode*>& nodes, int start, int end) {
        if (start > end) return nullptr;
        int mid = (start + end) / 2;
        TreeNode* root = nodes[mid];
        root->left = constructBalanceTree(nodes, start, mid-1);
        root->right = constructBalanceTree(nodes, mid+1, end);
        return root;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> nodes;
        travel(nodes, root);
        
        return constructBalanceTree(nodes, 0, nodes.size() - 1);
        
    }
};