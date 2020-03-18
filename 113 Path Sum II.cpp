#include "header.h"
// https://leetcode.com/problems/path-sum-ii/
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
    void search(TreeNode* root, int sum, vector<int> cur, vector<vector<int>> & result) {
        if (root == nullptr) return ;
        if (root->left == nullptr && root->right == nullptr) {
            // leaf reached
            if (root->val == sum) {
                cur.push_back(root->val);
                result.push_back(cur);
            } else return ;
        } else {
            cur.push_back(root->val);
            sum -= root->val;
            search(root->left, sum, cur, result);
            search(root->right, sum, cur, result);
        }
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        vector<int> cur;
        search(root, sum, cur, result);
        return result;
    }
};