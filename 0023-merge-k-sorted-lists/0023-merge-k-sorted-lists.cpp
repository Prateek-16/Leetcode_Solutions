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
    ListNode* merge(ListNode* l1 , ListNode* l2){
        ListNode dummy(0);
        ListNode* curr = &dummy;
        
        while(l1 && l2){
            if(l1->val > l2->val){
                curr->next = l2;
                l2 = l2->next;
            }
            else{
                curr->next = l1;
                l1 = l1->next;
            }
            curr = curr->next;
        }
        curr->next = l1 ? l1 : l2;
        
        return dummy.next;
    }
    
    ListNode* mergeListHelper(vector<ListNode*>& lists , int start , int end){
        if(start == end){
            return lists[start];
        }
        
        int mid = ( start + end ) / 2;
        
        ListNode* left = mergeListHelper(lists, start, mid);
        ListNode* right = mergeListHelper(lists, mid + 1, end);
        
        return merge(left , right);
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }
        int start = 0;
        int end = lists.size() - 1;
        return mergeListHelper(lists , start , end);
    }
};