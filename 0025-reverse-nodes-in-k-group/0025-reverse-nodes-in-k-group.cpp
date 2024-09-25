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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL) {
            return head;
        }
        ListNode* check = head;
        // Check if There are fewer than k nodes remaining
        for (int i = 0; i < k; i++) {
            if (check == NULL)
                return head;
            check = check->next;
        }

        // 1 case main solve karunga
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nextNode = NULL;
        int pos = 0;
        while (pos < k) {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
            pos++;
        }
        ListNode* recursionKaAns = NULL;
        
        recursionKaAns = reverseKGroup(nextNode, k);
        head->next = recursionKaAns;

        return prev;
    }
};