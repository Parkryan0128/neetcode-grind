# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        n = 0
        copy = head
        while copy:
            n += 1
            copy = copy.next
        
        if n == 1:
            return

        mid = n // 2
        mid_pointer = head
        while mid > 1:
            mid_pointer = mid_pointer.next
            mid -= 1
        
        temp = mid_pointer
        mid_pointer = mid_pointer.next
        temp.next = None

        curr = mid_pointer
        prev = None
        while curr:
            temp = curr.next
            curr.next = prev
            prev = curr
            curr = temp
        
        first = head
        second = prev
        while first:
            tmp1, tmp2 = first.next, second.next
            first.next = second
            if tmp1:
                second.next = tmp1         
            first, second = tmp1, tmp2


            
        
        


        