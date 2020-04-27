#include "header.h"
// https://leetcode.com/problems/reorder-list/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        // if (head == nullptr) return ;
        vector<ListNode*> ary;
        ListNode* p = head;
        while (p) {
            ary.push_back(p);
            p = p->next;
        }
        
        int n = ary.size() - 1;
        if (n <= 0) return ;
        // cout << n << endl;
        for (int i = 0; i < n/2; i++) {
            ary[i]->next = ary[n-i];
            ary[n-i]->next = ary[i+1];
            p = ary[i+1];
        }
        if (n & 1 && n > 1)
        p->next->next = nullptr;
        else if ((n & 1) == 0)
        p->next = nullptr;
        
    }
};