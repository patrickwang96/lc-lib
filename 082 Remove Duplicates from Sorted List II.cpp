
// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

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
        ListNode *ptr, *current;
        ListNode *dummy_head = new ListNode(0);
        dummy_head->next = head;
        ptr = head;
        current = dummy_head;
        
        bool duplicated = false;
        int dVal;
        
        while (ptr) {
            if (ptr->next && ptr->val == ptr->next->val) {
                duplicated = true;
                dVal = ptr->val;
                current->next = ptr->next;
                ptr = current->next;
            }
            else if (duplicated == true && dVal == ptr->val){
                current->next = ptr->next;
                ptr = current->next;
            }
            else {
                duplicated = false;
                current = ptr;
                ptr = current->next;
            }
        }
        
        return dummy_head->next;
    }
};