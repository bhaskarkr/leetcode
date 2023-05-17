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
    int pairSum(ListNode* head) {
           ListNode* slow = head, *fast = head->next, * prev = NULL;
           while(fast->next) {
               auto temp = slow->next;
               slow->next = prev;
               prev = slow;
               slow = temp;
               fast = fast->next->next;
           }
           ListNode* first = slow->next;
           slow->next = prev;
           int ans = 0;
           while(slow && first) {
               ans = max(slow->val + first->val, ans);
               slow = slow->next;
               first = first->next;
           }
           return ans;
    }

};
