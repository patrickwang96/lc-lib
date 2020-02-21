
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
俩ptr，间隔n，后一个ptr扫到list尾部即可用前一个ptr去remove item
*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* prevNode = head;
        ListNode* endNode = head;
        for (int i(0); i < n; i++)
            endNode = endNode->next;
        
        if (endNode == nullptr) {
            return head->next;
        }
        while(endNode->next != nullptr) {
            prevNode = prevNode->next;
            endNode = endNode->next;
        }
        if (prevNode->next != nullptr)
            prevNode->next = prevNode->next->next;
        else 
            prevNode->next = nullptr;
        return head;
    }
};