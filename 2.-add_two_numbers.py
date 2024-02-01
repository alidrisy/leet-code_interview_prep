#!/usr/bin/python3
"""2. Add Two Numbers"""
from typing import Optional


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
    """You are given two non-empty linked lists representing two non-negative integers.
    The digits are stored in reverse order, and each of their nodes contains a single digit.
    Add the two numbers and return the sum as a linked list.
    You may assume the two numbers do not contain any leading zero, except the number 0 itself.
    """
    rest = 0
    result: Optional[ListNode] = None
    res: Optional[ListNode] = None
    while True:
        num1 = 0
        num2 = 0
        sum = 0
        if l1 == None and l2 == None:
            if rest != 0:
                sum += rest
                rest = 0
                new_node = ListNode(sum)
                result.next = new_node
                result = result.next
            return res
        if l1 != None:
            num1 = l1.val
            l1 = l1.next
        if l2 != None:
            num2 = l2.val
            l2 = l2.next
        sum = num1 + num2
        if rest != 0:
            sum += rest
            rest = 0 
        str_sum = str(sum)
        if len(str_sum) > 1:
            sum = int(str_sum[1])
            rest = int(str_sum[0])
        
        if result == None:
            result = ListNode(sum)
            res = result
            
        else:
            new_node = ListNode(sum)
            result.next = new_node
            result = result.next
