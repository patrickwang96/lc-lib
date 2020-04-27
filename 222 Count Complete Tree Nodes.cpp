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
    bool search(TreeNode* root, bitset<32> index, int layer) {
        // check if the index-th (0 based) node in the last layer exist.
        for (int i = layer-1; i >=1; i--) {
            if (index[i]) root = root->right;
            else root = root->left;
        }
        if (index[0]) return root->right;
        else return root->left;
    }
    
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        int depth = 0;
        TreeNode* ptr = root;
        while (ptr) {
            ptr = ptr->left;
            depth++;
        }
        if (depth == 1) return 1;
        
        int result = (1 << (depth-1)) - 1;
        
        int mid, start = 0, end = result + 1;
        while (start < end) {
            mid = start + (end - start) / 2;
            bitset<32> path(mid);
            if (search(root, path, depth-1)) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }
        
        return result + start;
    }
};