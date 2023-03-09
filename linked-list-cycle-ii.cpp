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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow)
                break;
        }
        if(!fast || !fast->next)
            return NULL;
        while(fast && head != fast) {
            head = head->next;
            fast = fast->next;
        }
        return fast;
    }   
    // ListNode *detectCycle(ListNode *head) {
    //     set<ListNode*> visited;
    //     while(visited.find(head) == visited.end() && head) {
    //         visited.insert(head);
    //         head = head->next;
    //     }
    //     return head;
    // }
};
