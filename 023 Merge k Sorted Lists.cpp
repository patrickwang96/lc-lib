
// https://leetcode.com/problems/merge-k-sorted-lists/
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head;
        ListNode dummy(0);
        head = &dummy;
        ListNode* ptr = head;
        
        while (l1 && l2) {
            if (l1->val < l2->val) {
                ptr->next = l1;
                l1 = l1->next;
                ptr = ptr->next;
            }
            else {
                ptr->next = l2;
                l2 = l2->next;
                ptr = ptr->next;
            }
        }
        if (l1) ptr->next = l1;
        else ptr->next = l2;
        return head->next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if (lists.size() >= 2) {
            int k = lists.size();
            vector<ListNode*> l1(lists.begin(), lists.begin() + k/2);
            vector<ListNode*> l2(lists.begin() + k/2, lists.end());
            return mergeTwoLists(mergeKLists(l1), mergeKLists(l2));
        } 
        else if (lists.size() == 1) return lists[0];
        else return NULL;
    }
};