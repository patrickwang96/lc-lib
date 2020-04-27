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
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        if (cur == nullptr) 
            return cur;
        while (cur->next != nullptr) {
            ListNode* nextNode = cur->next;
            cur->next = nextNode->next;
            nextNode->next = head;
            head = nextNode;
        }
        return head;
    }
};