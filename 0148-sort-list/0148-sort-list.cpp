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
    ListNode* getMid(ListNode* head){
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* mergeList(ListNode* left , ListNode* right){
        ListNode* root = new ListNode(0);
        ListNode* dummy = root;
        
        while(left && right){
            if(left->val > right->val){
                dummy->next = right;
                right = right->next;
            }
            else{
                dummy->next = left;
                left = left->next;
            }
            dummy = dummy->next;
        }
        dummy->next = left ? left : right;
        return root->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        
        ListNode* mid = getMid(head);
        ListNode* left = head;
        ListNode* right = mid->next;
        
        mid->next = NULL;
        
        left = sortList(left);
        right = sortList(right);
        
        return mergeList(left, right);
    }
};