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
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* temp = head;
        ListNode* dummyNode = new ListNode(0,head);
        ListNode* prev = dummyNode;

        while(temp!= nullptr ){
            if(temp->next!=nullptr && temp->val == temp->next->val){
                while(temp->next!=nullptr && temp->val == temp->next->val){
                    ListNode* dup = temp;
                    temp = temp->next;
                    delete dup;
                }

                ListNode* dupl = temp;
                temp = temp->next;
                delete dupl;
               
                prev->next = temp;
            
            }
            else{
                prev = prev->next;
                temp = temp->next;
            }
        }
        
        return dummyNode->next;
        
    }
};