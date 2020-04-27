#include "header.h"
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
private:
    void solve(vector<int> &result, Node* root) {
        if (root == nullptr) return ;
        result.push_back(root->val);
        for (auto child: root->children) {
            solve(result, child);
        }
    }
public:
    vector<int> preorder(Node* root) {
        vector<int> ret;
        solve(ret, root);
        return ret;
        
    }
};