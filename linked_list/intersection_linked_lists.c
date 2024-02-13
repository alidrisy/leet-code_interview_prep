#include <stdio.h>
#include <stdlib.h>



 // Definition for singly-linked list.
 struct ListNode {
     int val;
      struct ListNode *next;
  };
 


/**
 * getIntersectionNode - find node at which the two linked lists intersect.
 * @headA: first linked list
 * @headA: second linked list
 * Return: the node at which the two lists intersect.
 * If the two linked lists have no intersection at all, return null.
*/

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *nodeB, *node = NULL;
    int s;
    nodeB = headB;
    
    while (headA)
    {
        s = 0;
        while (nodeB)
        {
            if (headA == nodeB)
            {
                s = 1;
                break;
            }
            nodeB = nodeB->next;
        }
        
        if (s == 1)
        {
            if (node == NULL)
            {
                node = headA;
            }
        }
        
        else
        {
            nodeB = headB;
            node = NULL;
        }
        headA = headA->next;
    }
    return (node);
}

