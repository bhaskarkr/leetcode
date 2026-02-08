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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        auto curr = head;
        auto prev = dummy;
        while(curr && curr->next) {
            auto third = curr->next->next;
            auto second = curr->next;
            auto first = curr;
            prev->next = second;
            second->next = first;
            first->next = third;
            prev = prev->next->next;
            curr = third;
        }
        return dummy->next;
    }
};
