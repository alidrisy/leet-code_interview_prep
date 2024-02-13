#include <stdio.h>
#include <stdlib.h>


typedef struct MyLinkedListNode {
    int val;
    struct MyLinkedListNode *next;
} MyLinkedListNode;


typedef struct MyLinkedList {
    int size;
    MyLinkedListNode *head;
} MyLinkedList;

MyLinkedList* myLinkedListCreate() {
    MyLinkedList *obj = malloc(sizeof(MyLinkedList));

    if (obj == NULL)
        return (NULL);
    obj->head = NULL;
    obj->size = 0;
    return (obj);
}

int myLinkedListGet(MyLinkedList* obj, int index) {
     int i = 0;
    MyLinkedListNode *cur;

    if (index < 0 || index >= obj->size)
        return (-1);

    cur = obj->head;
    while (i < index)
    {
        cur = cur->next;
        i++;
    }
    return (cur->val); 
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    MyLinkedListNode *new;
    new = malloc(sizeof(MyLinkedListNode));
    if (new == NULL)
        return;
    new->val = val;
    new->next = obj->head;
    obj->head = new;
    obj->size++;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
     MyLinkedListNode *new, *cur;

    new = malloc(sizeof(MyLinkedListNode));
    if (new == NULL)
        return;
    new->val = val;
    new->next = NULL;
    if (obj->head == NULL)
    {
        obj->head = new;
    } else {
    cur = obj->head;
    while (cur->next != NULL)
        cur = cur->next;
    cur->next = new;
    }
    obj->size++;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    MyLinkedListNode *new, *cur;
    int i = 0;
    if (index < 0 || index > obj->size)
        return;
    if (index == 0)
    {
        myLinkedListAddAtHead(obj, val);
        return;
    } else {
        new = malloc(sizeof(MyLinkedListNode));
        new->val = val;
        cur = obj->head;
        while (i < index - 1)
        {
            cur = cur->next;
            i++;
        }
        new->next = cur->next;
        cur->next = new;
        obj->size++;
    }
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
 MyLinkedListNode *new, *cur;
    int i = 0;

    if (index < 0 || index >= obj->size)
        return;

    cur = obj->head;

    if (index == 0)
    {
        obj->head = cur->next;
        free(cur);
        obj->size--;
        return;
    }

    while (i < index - 1)
    {
        cur = cur->next;
        i++;
    }
    new = cur->next;
    cur->next = cur->next->next;
    free(new);
    obj->size--;
}

void myLinkedListFree(MyLinkedList* obj) {
    MyLinkedListNode *cur;
    
    while (obj->head != NULL)
    {
        cur = obj->head;
        obj->head = obj->head->next;
        free(cur);
    }
    free(obj);
}


void printMyLinkedNode(MyLinkedListNode *obj)
{
    MyLinkedListNode *cur;

    cur = obj;
    while (cur)
    {
        printf("%d\n", cur->val);
        cur = cur->next;
    }
}

void reverseMyLinkedList(MyLinkedList *obj)
{
    MyLinkedListNode *new, *ne;

    new = NULL;

    while(obj->head)
    {
        ne = obj->head->next;
        obj->head->next = new;
        new = obj->head;
        obj->head = ne;
    }
    obj->head = new;
}

void printMyLinkedList(MyLinkedList *obj)
{
    int i = 0;
    MyLinkedListNode *cur;

    cur = obj->head;
    while (i < obj->size)
    {
        printf("%d\n", cur->val);
        cur = cur->next;
        i++;
    }
}

int main(void)
{
    MyLinkedList *head;

    head = myLinkedListCreate();
    myLinkedListAddAtTail(head, 0);
    myLinkedListAddAtTail(head, 1);
    myLinkedListAddAtTail(head, 2);
    myLinkedListAddAtTail(head, 3);
    myLinkedListAddAtTail(head, 4);
    myLinkedListAddAtTail(head, 98);
    myLinkedListAddAtTail(head, 402);
    myLinkedListAddAtTail(head, 1024);
    printMyLinkedList(head);
    reverseMyLinkedList(head);
    printf("-----------------\n");
    printMyLinkedList(head);
    myLinkedListFree(head);
    return (0);
}
