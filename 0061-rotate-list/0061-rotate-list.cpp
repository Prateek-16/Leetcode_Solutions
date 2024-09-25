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
    int getLength(ListNode* head){
        int len=0;
        while(head!=NULL){
            len++;
            head=head->next;
        }
        return len;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        int length = getLength(head);
        int rotations = k % length;
        
        if(rotations == 0){
            return head;
        }
        
        ListNode* ptr1 = head;
        ListNode* ptr2 = head;
        int i = 0;
        
        while(i < rotations){
            ptr2 = ptr2->next;
            i++;
        }
        
        while(ptr2->next != NULL){
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        ListNode* newHead = ptr1->next;
        ptr1->next = NULL;
        ptr2->next = head;
        
        return newHead;
    }
};