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
    vector<TreeNode*> construct(int s, int e) {
        vector<TreeNode*> result;
        if (s > e) return {nullptr};
        for (int i = s; i <= e; i++) {
            auto lefts = construct(s, i-1);
            auto rights = construct(i+1, e);
            for (auto l: lefts) {
                for (auto r: rights) {
                    TreeNode* n = new TreeNode(i);
                    n->left = l;
                    n->right = r;
                    result.push_back(n);
                }
            }
        }
        return result;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return construct(1, n);
        
    }
};