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
    void solve(TreeNode* root, vector<string> &ret, string cur) {
        cur += to_string(root->val) + "->";
        if (root->left == nullptr && root->right == nullptr) {
            ret.push_back(cur.substr(0, cur.size()-2));
        }
        if (root->left) solve(root->left, ret, cur);
        if (root->right) solve(root->right, ret, cur);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
        if (root == nullptr) return ret;
        solve(root, ret, "");
        return ret;
    }
};