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
        int carry = 0;
        ListNode* dummy = new ListNode(1);
        ListNode* prev = dummy;
        while(l1 || l2) {
            carry = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            if(l1) {
                prev->next = l1;
                l1->val = carry % 10;
                prev = l1;
            }
            else {
                prev->next = l2;
                l2->val = carry % 10;
                prev = l2;
            } 
            if(l1)
                l1 = l1->next;
            if(l2)
                l2 = l2->next;
            carry = carry / 10;
        }
        if(carry) {
            prev->next = new ListNode(carry);
        }
        return dummy->next;
    }
};
