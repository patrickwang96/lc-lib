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
    void solve(TreeNode* root, int cur, vector<int> &vec) {
        if (root == nullptr) return ;
        if (root->left == nullptr && root->right == nullptr) {
            cur = cur * 10 + root->val;
            vec.push_back(cur);
            return ;
        }
        cur = cur * 10 + root->val;
        if (root->left) {
            solve(root->left, cur, vec);
        }
        if (root->right) solve(root->right, cur, vec);
        return ;
    }
public:
    int sumNumbers(TreeNode* root) {
        if (root == nullptr) return 0;
        vector<int> vec;
        solve(root, 0, vec);
        return accumulate(vec.begin(), vec.end(), 0);
        
        
    }
};