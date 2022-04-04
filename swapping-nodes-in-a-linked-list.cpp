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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* start = head;
        int i = 1;
        while(i++<k && start) {
            start = start->next;
        }
        ListNode* end = head;
        ListNode* temp = start;
        while(temp->next) {
            temp = temp->next;
            end = end->next;
        }
        swap(start->val, end->val); 
        return head;
    }
};
