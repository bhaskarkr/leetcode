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
    ListNode* partition(ListNode* head, int x) {
        ListNode* first = new ListNode(1), * second  = new ListNode(1);
        ListNode* prev1 = first, * prev2  = second;
        while(head) {
            if(head->val < x) {
                prev1->next = head;
                prev1 = head;
            } else {
                prev2->next = head;
                prev2 = head;
            }
            head = head->next;
        }
        prev1->next = second->next;
        prev2->next = NULL;
        return first->next;
    }
};
