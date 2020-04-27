#include "header.h"
// https://leetcode.com/problems/intersection-of-two-linked-lists/
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> listNodeContainer;
        ListNode* nodeptr = headA;
        while(nodeptr != NULL) {
            listNodeContainer.insert(nodeptr);
            nodeptr = nodeptr->next;
        }
        
        nodeptr = headB;
        while(nodeptr != NULL) {
            if (listNodeContainer.count(nodeptr))
                return nodeptr;
            else
                nodeptr = nodeptr->next;
        }
        return NULL;
        
    }
};