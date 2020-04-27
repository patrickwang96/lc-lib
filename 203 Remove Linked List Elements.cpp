#include "header.h"
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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr) {
            return head;
        }
        ListNode* cur = head;
        
        while (cur->next != nullptr) {
            ListNode* p = cur->next;
            if (p->val == val) {
                cur->next = p->next;
            }
            else
                cur = cur->next;
            if (cur == nullptr) {
                break;
            }
        }
        if (head->val == val) {
            head = head->next;
        }
        return head;
        
        
    }
};