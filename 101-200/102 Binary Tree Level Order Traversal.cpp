#include "header.h"
// https://leetcode.com/problems/binary-tree-level-order-traversal/
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
    vector<int> parseQueue(queue<TreeNode*> & temp) {
        vector<int> result;
        int size = temp.size();
        for (int i = 0; i < size; i++) {
            TreeNode* tempNode = temp.front();
            temp.pop();
            result.push_back(tempNode->val);
            if (tempNode->left)
                temp.push(tempNode->left);
            if (tempNode->right)
                temp.push(tempNode->right);
        }
        return result;
    }
    
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> totalResult;
        if (root == NULL)
            return totalResult;
        queue<TreeNode*> queue;
        queue.push(root);
        while(!queue.empty()) {
            vector<int> tempResult = parseQueue(queue);
            totalResult.push_back(tempResult);
        }
        return totalResult;
    }
};