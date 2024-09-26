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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummyNode = new ListNode(0);
        dummyNode->next = head;
        
        ListNode* prev = dummyNode;
        ListNode* curr = head;
        
        while(curr){
            while(curr->next && curr->next->val == curr->val){
                curr = curr->next;
            }
            if(prev->next == curr){
                prev = curr;
            }
            else{
                prev->next = curr->next;
            }
            curr = curr->next;
        }
        return dummyNode->next;
        
    }
};