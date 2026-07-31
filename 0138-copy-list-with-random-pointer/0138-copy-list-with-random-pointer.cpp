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
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return head;
        
        Node* temp = head;
        //copying val
        while(temp!= nullptr){
            Node* CopyList = new Node(temp->val);
            CopyList->next = temp->next;
            temp->next = CopyList;
            temp = temp->next->next;
        }
        //connecting random ptr
        temp = head;
        while(temp!=nullptr){
            Node* CopyList = temp->next;

            if(temp->random!=nullptr) CopyList->random = temp->random->next;
            temp = CopyList->next;
        }
        //connecting next ptr

        Node* dummyNode = new Node(-1);
        Node* result = dummyNode;
        temp = head;
        while(temp!=nullptr){
            result->next = temp->next;
            temp->next = temp->next->next;
            result = result->next;
            temp = temp->next;
        }
        return dummyNode->next;
       
        
    }
};