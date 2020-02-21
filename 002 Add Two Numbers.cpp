
// https://leetcode.com/problems/add-two-numbers/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *ptr;
        ListNode dummy_head(0);
        ptr = &dummy_head;
        int digit_sum = 0;
        while (l1 && l2) {
            digit_sum = l1->val + l2->val + carry;
            carry = digit_sum / 10;
            digit_sum %= 10;
            l1 = l1->next;
            l2 = l2->next;
            
            ptr->next = new ListNode(digit_sum);
            ptr = ptr->next;
             
        }
        
        if (l1 || l2){
            if (l2) l1 = l2;
            // l1 is the unfinished list now
            while (l1){
                digit_sum = l1->val + carry;
                carry = digit_sum / 10;
                digit_sum %= 10;
                ptr->next = new ListNode(digit_sum);
                ptr = ptr->next;
                l1 = l1->next;
            }
        }
        if (carry) ptr->next = new ListNode(carry);
        
        return dummy_head.next;
    }
};