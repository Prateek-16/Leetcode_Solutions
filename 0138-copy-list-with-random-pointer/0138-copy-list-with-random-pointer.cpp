/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* deepcopy(Node* head) {
        //NULL Check
        if (!head) {
            return head;
        }
        Node* temp = head;
        
        //Creating Duplicate Nodes
        while (temp) {
            Node* newnode = new Node(temp->val);
            newnode->next = temp->next;
            temp->next = newnode;
            temp = temp->next->next;
        }
        
        temp = head;
        
        //Assigning Random pointers for Duplicate Nodes
        while (temp) {
            temp->next->random = temp->random ? temp->random->next : NULL;
            temp = temp->next->next;
        }

        temp = head;
        
        //Seperating Original LL and Copy LL
        Node* clonedHead = temp->next;
        while (temp) {
            Node* clonedNode = temp->next;
            temp->next = temp->next->next;
            if (clonedNode->next) {
                clonedNode->next = clonedNode->next->next;
            }
            temp = temp->next;
        }
        return clonedHead;
    }
    Node* copyRandomList(Node* head) { return deepcopy(head); }
};