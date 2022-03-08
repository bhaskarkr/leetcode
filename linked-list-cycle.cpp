/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head)
            return false;
        ListNode* first = head;
        ListNode* second = head->next;
        while(first && second) {
            if(first == second)
                return true;
            first = first->next;
            second = second->next;
            if(second)
                second = second->next;
        }
        return false;
    }
};
