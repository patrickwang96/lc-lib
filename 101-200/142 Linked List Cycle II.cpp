#include "header.h"
// https://leetcode.com/problems/linked-list-cycle-ii/
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
    ListNode* stepForward(int step, ListNode* mover) {
        if (mover == nullptr) {
            return nullptr;
        }
        // return nullptr if reach the end of linked list
        for (int i(0); i < step; i++) {
            mover = mover->next;
            if (mover == nullptr)
                return nullptr;
        }
        return mover;
    }
    
    ListNode *detectCycle(ListNode *head) {
        int currentPosition = 0;
        bool hasCycle = false;
        ListNode* fastptr = head;
        ListNode* slowptr = head;
        while (fastptr != nullptr && slowptr != nullptr) {
            fastptr = stepForward(2, fastptr);
            slowptr = stepForward(1, slowptr);
            currentPosition++;
            if (fastptr != nullptr && fastptr == slowptr) {
                hasCycle = true;
                break;
            }
        }
        if (hasCycle) {
            slowptr = head;
            while (fastptr != slowptr) {
                fastptr = stepForward(1, fastptr);
                slowptr = stepForward(1, slowptr);
            }
            return fastptr;
            
        }
        else {
            return NULL;
        }
    }
};