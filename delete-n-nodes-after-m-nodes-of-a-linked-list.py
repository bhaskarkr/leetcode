# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteNodes(self, head: ListNode, m: int, n: int) -> ListNode:
        curr = head
        prev = head
        while curr != None:
            M = m
            while M > 0 and curr != None:
                M -= 1
                prev = curr
                curr = curr.next
            N = n
            while N > 0 and curr != None:
                N -= 1
                curr = curr.next
            prev.next = curr
        return head
