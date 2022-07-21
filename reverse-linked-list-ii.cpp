/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
        
        [1,2,3,4,5], left = 2, right = 4
        [dummy , 1,    2,    3,   4,   5]
           ^     ^     ^     ^
           |     |     |     |
               prev  first  end
               
               
                ---------------
                |             |
                |     ------- |
                |     |     | |
                |     \/    | \/
       [dummy , 1,    2,     3,   4,   5]
                      |           ^
                      ------------| 
           ^     ^     ^     ^
           |     |     |     |
               prev  first  end
               
       [dummy ,   1,     3,   2,    4,   5]
           ^      ^           ^     ^
           |      |           |     |
                 prev       first  end
             
       [dummy ,   1,     4,   3,    2,    5]
           ^      ^                 ^     ^
           |      |                 |     |
                 prev             first  end
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head)
            return head;
        ListNode* prev = new ListNode(-1);
        ListNode* dummy = prev;
        dummy->next = head;
        int i = 1;
        while(i < left) {
            i++;
            prev = prev->next;
        }
        ListNode* first = prev->next;
        ListNode* end  = first->next;
        while(i < right) {
            first->next = end->next;
            end->next = prev->next;
            prev->next = end;
            end = first->next;
            i++;
        }
        return dummy->next;
    }
};
