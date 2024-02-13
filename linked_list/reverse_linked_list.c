#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};
 


/**
 * reverseList - reverse the linked list.
 * @head: linked list head
 * Return: the reversed linked list.
*/

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *new = NULL;
    struct ListNode *ne = NULL;
    
    while (head)
    {
        ne = head->next;
        head->next = new;
        new = head;
        head = ne;
    }
    
    head = new;
    
    return (head);
}
