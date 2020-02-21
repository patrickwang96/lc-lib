
// https://leetcode.com/problems/rotate-list/

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
    int getLength(ListNode* head){
        int result = 0;
        ListNode* ptr = head;
        while(ptr){
            ptr = ptr->next;
            result++;
        }
        return result;
    }
    
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) return head;
        
        int length = getLength(head);
        k %= length;
        if (k == 0) return head;
        int index = length - k;
        
        ListNode* newHead = head;
        ListNode* newTail;
        for (int i = 0; i < index - 1; i++)
            newHead = newHead->next;
        newTail = newHead;
        newHead = newTail->next;
        
        ListNode* oldTail = newHead;
        while(oldTail->next) {
            oldTail = oldTail->next;
        }
        
        oldTail->next = head;
        newTail->next = nullptr;
        return newHead;
    }
};