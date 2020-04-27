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
    
    inline bool isLeaf(TreeNode* node) {
        return node && !node->left && !node->right;
    }
    
    void dfs(TreeNode* root, vector<int>& seq) {
        if (!root) return ;
        if (isLeaf(root)) {
            seq.push_back(root->val);
            return ;
        }
        dfs(root->left, seq);
        dfs(root->right, seq);
    }
    
    vector<int> getLeaf(TreeNode* root) {
        vector<int> ret;
        dfs(root, ret);
        return ret;
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> s1 = getLeaf(root1);
        vector<int> s2 = getLeaf(root2);
        
        if (s1.size() != s2.size()) return false;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) return false;
        }
        return true;
        
    }
};