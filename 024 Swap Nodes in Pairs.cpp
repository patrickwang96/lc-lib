
// https://leetcode.com/problems/swap-nodes-in-pairs/

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
   // recursion
    ListNode* swapPairs(ListNode* head) {
        // if list length is less than 2, just return
        if (head == nullptr) return head;
        if (head->next == nullptr) return head;
        ListNode *p1, *p2, *p3;
        p1 = head;
        p2 = head->next;
        p3 = head->next->next;
        p2->next = p1;
        head = p2;
        p1->next = swapPairs(p3);
        
        return head;
       
    }
};

