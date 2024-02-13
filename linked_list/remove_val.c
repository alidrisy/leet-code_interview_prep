#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};
 


/**
 * reverseList - remove all the nodes of the linked list where head.val = val
 * @head: linked list head
 * @val: the value/integer to delet.
 * Return: the new head of linked list.
*/

struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode *node, *cur;

    if (head == NULL)
    {
        return (NULL);
    }
    
    cur = head;

    if (val == head->val)
    {
        head = cur->next;
        free(cur);
        return removeElements(head, val);
    }

    while (cur && cur->next)
    {
        if (cur->next->val == val)
        {
            node = cur->next;
            if (cur->next->next)
            {
                cur->next = cur->next->next;
            }
            else
            {
                cur->next = NULL;
            }
            free(node);
            continue;
        }
        cur = cur->next;
    }
    
    return (head);
}