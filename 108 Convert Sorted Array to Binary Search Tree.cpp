#include "header.h"
// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
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
    TreeNode* constructTree(vector<int> &nums, int left, int right) {
        if (right < left) return nullptr;
        TreeNode* root;
        int mid = (right + left) / 2;
        root = new TreeNode(nums[mid]);
        root->left = constructTree(nums, left, mid - 1);
        root->right = constructTree(nums, mid + 1, right);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return constructTree(nums, 0, nums.size() - 1);
        
    }
};