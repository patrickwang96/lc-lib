#include "header.h"
// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* constructTree(vector<int> &nums, int left, int right) {
        if (right < left) return nullptr;
        TreeNode* root;
        int mid = (right + left) / 2;
        root = new TreeNode(nums[mid]);
        root->left = constructTree(nums, left, mid - 1);
        root->right = constructTree(nums, mid + 1, right);
        return root;
    }
    
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        while (head) {
            nums.push_back(head->val);
            head = head->next;
        }
        return constructTree(nums, 0, nums.size() - 1);  
    }
};