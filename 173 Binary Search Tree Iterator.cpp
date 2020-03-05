
// https://leetcode.com/problems/binary-search-tree-iterator/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
    stack<TreeNode*> node_stack;
public:
    BSTIterator(TreeNode* root) {
        TreeNode* ptr = root;
        while (ptr) {
            node_stack.push(ptr);
            ptr = ptr->left;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* ptr;
        int result;
        ptr = node_stack.top();
        node_stack.pop();
        result = ptr->val;
        if (ptr->right) {
            ptr = ptr->right;
            while (ptr) {
                node_stack.push(ptr);
                ptr = ptr->left;
            }
        }
        return result;
        
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !node_stack.empty();
        
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */