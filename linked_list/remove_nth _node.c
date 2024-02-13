#include <stdio.h>
#include <stdlib.h>

 // Definition for singly-linked list.
 struct ListNode {
     int val;
      struct ListNode *next;
  };
 


/**
 * removeNthFromEnd - remove the nth node from the end of the linked list.
 * @head: linked list head
 * Return: the linked list head.
*/

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *new, *ne;
    int i = 0, idx = 0;
    
    new = head;
    
    while (new) 
    {
        new = new->next;
        idx++;
    }
    
    idx -= n;
    new = head;

    if (idx == 0)
    {
        head = new->next;
        free(new);
        return (head);
    }
    
        
    while (new) 
    {
        if (i == idx - 1)
        {
            ne = new->next;
            new->next = ne->next;
            free(ne);
        }
        i++;
        new = new->next;
    }
    return (head);
}
