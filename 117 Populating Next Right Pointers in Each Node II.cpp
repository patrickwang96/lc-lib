#include "header.h"
// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
private: 
    void parseQueue(queue<TreeLinkNode*>& nodeQueue) {
        TreeLinkNode* prevNode = NULL;
        int size = nodeQueue.size();
        for (int i = 0; i < size; i++) {
            TreeLinkNode* temp = nodeQueue.front(); 
            nodeQueue.pop();
            if (prevNode) {
                prevNode->next = temp;
            }
            if (temp->left) {
                nodeQueue.push(temp->left);
            }
            if (temp->right) {
                nodeQueue.push(temp->right);
            }
            
            prevNode = temp;
            
        }
    }
public:
    void connect(TreeLinkNode *root) {
        queue<TreeLinkNode*> nodeQueue;
        if (root == NULL) {
            return ;
        }
        
        nodeQueue.push(root);
        
        while (!nodeQueue.empty()) {
            parseQueue(nodeQueue);
        }
        
    }
};