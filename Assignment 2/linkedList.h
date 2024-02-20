#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct LinkedList
{
    int size;
    struct ListNode *first_node;
    struct ListNode *final_node;
}LinkedList;

typedef struct ListNode
{
    void *data;
    struct ListNode *next_node;
    struct ListNode *last_node;
}ListNode;

LinkedList* createLinkedList();
void insertStart(LinkedList* list, void* entry);
void insertLast(LinkedList *list, void *entry);
void* removeStart(LinkedList *list);
void* removeLast(LinkedList *list);

typedef void (*listFunc)(void *data);

void printLinkedList(LinkedList *list, listFunc funcPtr);
void freeLinkedList(LinkedList *list, listFunc funcPtr);

void print_with_string(void *data);

#endif
