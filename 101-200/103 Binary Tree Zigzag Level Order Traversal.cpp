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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> candidate;
        
        if (root == nullptr) return result;
        candidate.push(root);
        int count = 0;
        while (!candidate.empty()) {
            vector<int> layer;
            int num = candidate.size();
            for (int i = 0; i < num; i++) {
                auto node = candidate.front();
                candidate.pop();
                layer.push_back(node->val);
                if (node->left) candidate.push(node->left);
                if (node->right) candidate.push(node->right);
                
            }
            if (count & 1) reverse(layer.begin(), layer.end());
            result.push_back(layer);
            count++;
        }
        
        return result;
        
    }
};