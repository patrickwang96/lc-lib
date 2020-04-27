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
    int check_depth(TreeNode* root) {
        if (root == nullptr) return 0;
        queue<TreeNode*> q;
        int counter = 0;
        q.push(root);
        
        while (!q.empty()) {
            int n = q.size();
            counter ++;
            for (int i = 0; i < n; i++) {
                auto node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            
        }   
        return counter;
    }
    
    int solve(TreeNode* root, int depth) {
        if (depth == 0) return 0;
        int counter = 0;
        queue<TreeNode*> q;
        q.push(root);
        int ret = 0;
        
        while (!q.empty()) {
            int n = q.size();
            counter++;
            for (int i = 0; i < n; i++) {
                auto node = q.front();
                q.pop();
                if (counter == depth) ret += node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                
            }
        }
        return ret;
    }
public:
    int deepestLeavesSum(TreeNode* root) {
        int depth = check_depth(root);
        int sum = solve(root, depth);
        return sum;
        
    }
};