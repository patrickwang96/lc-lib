
// https://leetcode.com/problems/linked-list-cycle/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode* stepForward(ListNode* ptr, int step) {
        for (int i = 0; i < step; i++) {
            if (ptr->next) ptr = ptr->next;
            else return nullptr;
        }
        return ptr;
    }
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr) return false;
        ListNode* p1, *p2;
        
        p1 = head;
        p2 = head->next;
        if (p2 == nullptr) return false; // list length == 1
        
        while (p1 != p2) {
            if (p2 == nullptr) return false;
            else {
                p1 = stepForward(p1, 1);
                p2 = stepForward(p2, 2);
            }
        }
        return true;
        
    }
};