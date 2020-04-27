#include "header.h"
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
    ListNode* middleNode(ListNode* head) {
        if (head == nullptr) return nullptr;
        // ListNode* p1, *p2;
        // p1 = p2 = head;
        // while (p2->next) {
        //     p1 = p1->next;
        //     p2 = p2->next;
        //     if (p2 == nullptr) break;
        //     else p2 = p2->next;
        // }
        // return p1;
        vector<ListNode*> v;
        ListNode* p = head;
        while (p) {
            v.push_back(p);
            p = p->next;
        }
        
        int mid = v.size() / 2;
        return v[mid];
    }
};