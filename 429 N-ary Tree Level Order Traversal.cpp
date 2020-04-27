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
    
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ret;
        if (root == nullptr) return ret;
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()) {
            int n = q.size();
            vector<int> layer(n);
            for (int i = 0; i < n; i++) {
                Node* p = q.front();
                q.pop();
                layer[i] = p->val;
                for (auto child: p->children)
                    q.push(child);
            }
            ret.push_back(layer);
        }
        return ret;
    }
};