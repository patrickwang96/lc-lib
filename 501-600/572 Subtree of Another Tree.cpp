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
    bool same(TreeNode* a, TreeNode* b) {
        if (a == nullptr && b == nullptr) return true;
        else if (a == nullptr || b == nullptr) return false;
        if (a->val != b->val) return false;
        return same(a->left, b->left) && same(a->right, b->right);
    }
    
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (s == nullptr && t == nullptr) return true;
        if (same(s, t)) return true;
        if (s == nullptr || t == nullptr) return false;
        if (isSubtree(s->left, t) || isSubtree(s->right, t)) return true;
        else return false;
    }
};