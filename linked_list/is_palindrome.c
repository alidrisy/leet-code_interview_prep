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

int len_list(struct ListNode *new)
{
int x = 0;

while (new != NULL)
{
new = new->next;
x++;
}
return (x);
}

/**
* is_plindrome - check if the linked list is plindrome
* @head: a pointer to linked list
* Return: true if yes false if no
*/

bool isPalindrome(struct ListNode* head) 
{
	int *node, i, x = 0, c;
	struct ListNode *new;

	if (head == NULL)
	return (true);
	new = head;
	c = len_list(new);
	node =(int *)  malloc(sizeof(int) * c);
	while (new != NULL)
	{
		node[x] = new->val;
		x++;
		new = new->next;
	}
	for (i = 0, x = c - 1; i < x; i++, x--)
	{
		if (node[i] != node[x])
		return (false);
	}
	return (true);
}
