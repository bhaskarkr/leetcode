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
    ListNode* reverseKGroup(ListNode* head, int K) {
        if(!head)
            return head;
        int k = K;
        ListNode *start = head, *curr = head, *prev = head, *next = NULL;
        while(k > 0) {
            if(!curr)
                return head;
            curr = curr->next;
            k--;
        }
        curr = head;
        k = K;
        while(curr && k > 0) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            k--;
        }
        start->next = reverseKGroup(next, K);
        return prev;
    }
};

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
