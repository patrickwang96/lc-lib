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
    int traverse(TreeNode* root, unordered_map<int, int> &map, int &count) {
        if (root == nullptr) return 0;
        int left_sum = traverse(root->left, map, count);
        int right_sum = traverse(root->right, map, count);
        
        int total_sum = left_sum + right_sum + root->val;
        
        // consider current tree sum only cause subtrees are considered in the recursion
        map[total_sum]++;
        count = max(count, map[total_sum]);
        return total_sum;
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> map;
        int count = 0;
        traverse(root, map, count);
        vector<int> ret;
        
        for (auto e: map) 
            if (e.second == count) ret.push_back(e.first);
        
        return ret;
    }
};