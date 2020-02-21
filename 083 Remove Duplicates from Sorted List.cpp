
// https://leetcode.com/problems/remove-duplicates-from-sorted-list/

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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return head;
        ListNode* ptr = head;
        while (ptr->next) {
            if (ptr->next->val == ptr->val) ptr->next = ptr->next->next;
            else ptr = ptr->next;
        }
        return head;
        
    }
};