#include "header.h"
// https://leetcode.com/problems/partition-list/

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
    ListNode* partition(ListNode* head, int x) {
        ListNode* h1, *h2, *current, *p1, *p2;
        h1 = new ListNode(0);
        h2 = new ListNode(0);
        p1 = h1;
        p2 = h2;
        
        current = head;
        while (current) {
            if (current->val < x) {
                p1->next = current;
                p1 = current;
            }
            else {
                p2->next = current;
                p2 = current;
            }
            current = current->next;
        }
        
        p1->next = h2->next;
        p2->next = nullptr;
        return h1->next;
    }
};