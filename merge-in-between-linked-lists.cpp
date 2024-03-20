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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* first = list1, *second = list1;
        int c = 0;
        while(c < a - 1 && first) {
            c++;
            first = first->next;
        }
        second = first->next;
        first->next = list2;
        while(c < b && second) {
            c++;
            second = second->next;
        }
        
        while(list2->next)
            list2 = list2->next;
        list2->next = second;
        return list1;
    }
};
