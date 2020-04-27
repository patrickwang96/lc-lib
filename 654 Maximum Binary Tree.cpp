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
    TreeNode* solve(vector<int>::iterator l, vector<int>:: iterator r) {
        auto iter = max_element(l, r+1);
        auto root = new TreeNode(*iter);
        if (iter != l) {
            root->left = solve(l, iter-1);
        }
        if (iter != r) {
            root->right = solve(iter+1, r);
        }
        return root;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.size() == 0) return nullptr;
        return solve(nums.begin(), nums.end() -1);
        
    }
};