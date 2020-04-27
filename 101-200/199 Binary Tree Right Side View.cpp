#include "header.h"
// https://leetcode.com/problems/binary-tree-right-side-view/
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
    void layerView(vector<TreeNode*> nodes, vector<int>& vec) {
        vector<TreeNode*> nextLayer;
        if (nodes.size() == 0) return ;
        
        vec.push_back(nodes.back()->val);
        for (auto n: nodes) {
            if (n->left) nextLayer.push_back(n->left);
            if (n->right) nextLayer.push_back(n->right);
        }
        layerView(nextLayer, vec);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        vector<TreeNode*> nodes;
        if (root == nullptr) return result;
        nodes.push_back(root);
        
        layerView(nodes, result);
        return result;
        
    }
};