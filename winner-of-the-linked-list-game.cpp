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
    string gameResult(ListNode* head) {
        int odd = 0;
        while(head) {
            if(head->val < head->next->val)
                odd++;
            else
                odd--;
            head = head->next->next;
        }
        return odd == 0 ? "Tie" : odd < 0 ? "Even" : "Odd";
    }   
};
