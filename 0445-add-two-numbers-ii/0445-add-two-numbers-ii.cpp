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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr || l2 == nullptr) return nullptr;
        
        ListNode* result = nullptr;
        int carry = 0;
        int sum = 0;
        stack<int> st1;
        stack<int> st2;

        while(l1!= nullptr ){
            st1.push(l1->val); 
            l1 = l1->next;
 
        }
        while(l2!= nullptr){
            st2.push(l2->val);
            l2= l2->next;
        }
        while(!st1.empty() || !st2.empty() || carry!= 0){
            int digit1 = st1.empty() ? 0 : st1.top();
            int digit2 = st2.empty() ? 0: st2.top();
            if(!st1.empty()) st1.pop();
            if(!st2.empty()) st2.pop();

            sum = digit1 + digit2 + carry;
            carry = sum/10;
            int digit = sum % 10;

            ListNode* newNode = new ListNode(digit);
            newNode->next = result;
            result = newNode;

        }
        return result;

    }
};