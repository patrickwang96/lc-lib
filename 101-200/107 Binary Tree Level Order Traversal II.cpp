#include "header.h"
// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) {
            return result;
        }
        
        queue<TreeNode*> layer;
        layer.push(root);
        while (!layer.empty()) {
            
            vector<int> vals;
            int times = layer.size();
            for (int i = 0; i < times; i++) {
                TreeNode* p = layer.front();
                layer.pop();
                vals.push_back(p->val);
                if (p->left) layer.push(p->left);
                if (p->right) layer.push(p->right);
            }
            result.push_back(vals);
            
        }
        vector<vector<int>> final_result(result.rbegin(), result.rend());
        return final_result;
        
    }
};