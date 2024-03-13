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
    ListNode* frequenciesOfElements(ListNode* head) {
        unordered_map<int , int> umap;
        ListNode* dummy = new ListNode(0);
        while(head) {
            umap[head->val]++;
            head = head->next;
        }
            
        auto curr = dummy;
        for(auto &[k, v] : umap) {
            curr->next = new ListNode(v);
            curr = curr->next;
        }
        return dummy->next;
    }
};
