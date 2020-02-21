
// https://leetcode.com/problems/reverse-linked-list-ii/

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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == nullptr || n==m) return head;
        ListNode dummy(0);
        dummy.next = head;
        
        ListNode* pre_m, *after_n, *ptr, *next, *nextTwo, *pm, *pn;
        pre_m = &dummy;
        for (int i = 0; i < m - 1; i++) {
            pre_m = pre_m->next;
        }
        ptr = pre_m->next; // ptr - m
        next = ptr->next;
        pm = ptr;
        
        int delta = n - m;
        for (int i = 0; i < delta; i++){
            after_n = next->next;
            next->next = ptr;
            pn = next;
            ptr = next;
            next = after_n;
        }
        
        pre_m->next = pn;
        pm->next = after_n;
        return dummy.next;
    }
};