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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* prev = head;
        ListNode* cur = head->next;
        
        while (cur != nullptr && cur->next != nullptr) {
            ListNode* nodeAfterCur = cur->next;
            cur->next = nodeAfterCur->next;
            nodeAfterCur->next = prev->next;
            prev->next = nodeAfterCur;
            
            cur = cur->next;
            prev = prev->next;
        }
        return head;
    }
};