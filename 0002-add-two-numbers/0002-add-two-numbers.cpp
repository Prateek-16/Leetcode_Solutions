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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        int carry = 0;
        
        while(l1 != NULL || l2 != NULL){
            
            int sum = (l1 != NULL ? l1->val : 0) + (l2 != NULL ? l2->val : 0) + carry;
            int curr_val = sum % 10;
            carry = sum / 10;
            
            temp->next = new ListNode(curr_val);
            temp = temp->next;
            l1 = l1 != NULL ? l1->next : l1;
            l2 = l2 != NULL ? l2->next : l2;
        }
        if(carry){
            temp->next = new ListNode(carry % 10);
            carry /= 10;
        }
        return dummy->next;
    }
};