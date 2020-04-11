#include "header.h"
// https://leetcode.com/problems/reverse-nodes-in-k-group/
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
    int length(ListNode* l) {
        int result = 0;
        while(l) {
            l = l->next;
            result++;
        }
        return result;
    }
    
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* next, *h, *p, *t;
        h =head;
        t = head;
        // if (h == nullptr) return h;
        if (length(h)<k) return h;
        p = h->next;
        
        for (int i = 0; i < k-1 ; i++) {
            if (p == nullptr) break;
            next = p->next;
            p->next = h;
            h = p;
            p = next;
        }
        
        t->next = reverseKGroup(p, k);
        
        return h;
    }
};