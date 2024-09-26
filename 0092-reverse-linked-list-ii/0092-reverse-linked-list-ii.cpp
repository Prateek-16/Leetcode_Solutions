/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* prevptr = dummy;
        
        for(int i = 0;i<(left - 1);i++){
            prevptr = prevptr->next;
        }
        ListNode* curr = prevptr->next;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        
        for(int i = 0 ; i < right - left + 1;i++){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        prevptr->next->next = curr;
        prevptr->next = prev;
        
        ListNode* newHead = dummy->next;
        dummy->next = NULL;
        delete dummy;
        return newHead;
    }
};