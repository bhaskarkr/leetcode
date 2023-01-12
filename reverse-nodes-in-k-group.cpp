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
    ListNode* reverseKGroup(ListNode* head, int k) {
        return helper(NULL, head, k);
    }

    ListNode* helper(ListNode* prev, ListNode* curr, int k) {
        if(!curr)
            return curr;
        ListNode* start = curr;
        int i = k;
        while(curr && i--) {
            curr = curr->next ;
        }
        if(i > 0)
            return start;
        i = k;
        curr = start;
        while(i-- && curr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        start->next = helper(start, curr, k);
        return prev;
    }
};
