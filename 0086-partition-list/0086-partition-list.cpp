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
    ListNode* partition(ListNode* head, int x) {
        ListNode* lesshead = new ListNode();
        ListNode* greaterhead = new ListNode();
        
        ListNode* lesstail = lesshead;
        ListNode* greatertail = greaterhead;
        
        ListNode* it = head;
        
        while(it){
            if(it->val < x){
                lesstail->next = it;
                lesstail = lesstail->next;
            }
            else{
                greatertail->next = it;
                greatertail = greatertail->next;
            }
            it = it->next;
        }
        lesstail->next = greaterhead->next;
        greatertail->next = NULL;
        
        return lesshead->next;
    }
};