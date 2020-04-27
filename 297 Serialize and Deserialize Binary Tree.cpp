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
class Codec {
private:
    string encode_vector(vector<int>& v) {
        string result = "";
        for (auto i: v) {
            result += to_string(i) + ",";
        }
        return result;
    }
    
    vector<int> decode_vector(string s) {
        vector<int> result;
        int p1 = 0, p2 = 0;
        int buf = 0;
        while (p1 < s.size()) {
            while (p2 < s.size() && s[p2] != ',') p2++;
            string tmp = s.substr(p1, p2-p1);
            result.push_back(stoi(tmp));
            p1 = ++p2;
        }
        return result;
    }
    
    
    void destruct(TreeNode* root, vector<int> &container) {
        if (root == nullptr) {
            container.push_back(INT_MIN);
            return ;
        }
        container.push_back(root->val);
        destruct(root->left, container);
        destruct(root->right, container);
        return ;
    }
    
    int construct(TreeNode*& root, vector<int> &container,int i) {
        if (container[i] == INT_MIN) {
            root = nullptr;
            return i;
        }
        root = new TreeNode(0);
        root->val = container[i];
        i = construct(root->left, container, i+1);
        i = construct(root->right, container, i+1);
        return i;
    }
    
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<int> container;
        destruct(root, container);
        
        return encode_vector(container);
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> container = decode_vector(data);
        TreeNode* root = nullptr;
        construct(root, container, 0);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));