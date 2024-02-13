#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};
 


/**
 * oddEvenList - group all the nodes with odd indices together
 * followed by the nodes with even indices.
 * @head: linked list head
 * Return: the reordered linked list.
*/


struct ListNode* oddEvenList(struct ListNode* head) {
    if (!head || !head->next) {
        return head;
    }

    struct ListNode *odd = head, *even = head->next, *evenHead = even;

    while (even && even->next) {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }

    odd->next = evenHead;

    return head;
}


/* anouther way to solve it */

struct ListNode* oddEvenList(struct ListNode* head) {
    struct ListNode *odd, *even, *oddN, *evenN, *ne;
    int i = 1;
    
    odd = NULL;
    even = NULL;
    
    if (head == NULL)
    {
        return (NULL);
    }
    
    
    while (head)
    {
        ne = head->next;
        if (i == 1 || i % 2 != 0)
        {
            if (!odd)
            {
                odd = head;
                odd->next = NULL;
                oddN = odd;
            }
            else
            {
                oddN->next = head;
                oddN = oddN->next;
                oddN->next = NULL;
            }
        }
        else
        {
            if (!even)
            {
                even = head;
                even->next = NULL;
                evenN = even;
            }
            else
            {
                evenN->next = head;
                evenN = evenN->next;
                evenN->next = NULL;
            }
        }
        i++;
        head = ne;
    }
    oddN->next = even;
    head = odd;
    return (head);
}
