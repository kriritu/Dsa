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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if( head == nullptr || head->next == nullptr) return head;
        ListNode* dummynode = new ListNode(-1) ;
        dummynode->next = head;

        ListNode* sublist = dummynode;
        for(int i = 0; i< left-1; i++){
            sublist = sublist->next;
        }
        ListNode* subhead = sublist->next;
        ListNode* curr = subhead;
        ListNode* prev= nullptr;
        ListNode* fowd;
        int steps = right- left +1;

        while(steps > 0){
            fowd = curr->next;
            curr->next= prev;
            prev = curr;
            curr = fowd;
            steps--;
        }
        subhead->next = curr;
        sublist->next = prev;

        return dummynode->next;

    }
    
};