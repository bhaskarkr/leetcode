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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k == 0)
            return head;
        ListNode* end = head;
        int n = 0;
        while(end) {
            n++; 
            end = end->next;
        }
        if(n) {
            k = k%n;
        }
        end = head;
        while(end && k--)
            end = end->next;
        ListNode* start = head;
        while(end && end->next) {
            start = start->next;
            end = end->next;
        }
        if(start && end) {
            end->next = head;
            head = start->next;
            start->next = nullptr;
        }
        return head;
    }
};
