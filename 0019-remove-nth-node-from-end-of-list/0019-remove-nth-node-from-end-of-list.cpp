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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ptr1 = head;
        ListNode* ptr2 = head;
        int i = 0;
        while(i < n){
            ptr2=ptr2->next;
            i++;
        }
        if(ptr2 == NULL){
            return head->next;
        }
        while(ptr2->next != NULL){
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        ptr1->next = ptr1->next->next;
        return head;
    }
};