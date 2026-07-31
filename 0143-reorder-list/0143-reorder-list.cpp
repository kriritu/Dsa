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
    ListNode* reverseList(ListNode* head) {

        if(head == NULL || head->next == NULL) return head;

        ListNode *curr = head;
        ListNode *prev = NULL;
        ListNode *forw = head->next;
        
        while(curr != NULL){
            forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
             
        }
        return prev;
        
    }
    void merge(ListNode*head1, ListNode* head2){
        ListNode* temp1 = head1;
        ListNode* temp2 = head2;
       
        
        while(temp1!= nullptr && temp2!= nullptr){
            ListNode* curr1 = temp1->next;
            ListNode* curr2 = temp2->next;
            temp1->next = temp2;
            if(curr1 == nullptr) break; //first list ended
            
            temp2->next = curr1;
            temp1 = curr1;
            temp2 = curr2;
            
        }
        
    }
    void reorderList(ListNode* head) {
        if(!head || !head->next ||!head->next->next) return;

        ListNode* temp = head;
        ListNode* slow = temp;
        ListNode* fast = temp;

        while(fast!= nullptr && fast->next!= nullptr){
            slow = slow->next;
            fast= fast->next->next;
        }
        //break list completely
        ListNode* list2 = slow->next;
        slow->next = nullptr;

        ListNode* reversedlist = reverseList(list2);

        merge(head, reversedlist);

    }
};