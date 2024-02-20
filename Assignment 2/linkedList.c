#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"

LinkedList* createLinkedList()
{
    LinkedList *new_list = (LinkedList*)malloc(sizeof(LinkedList));
    new_list->first_node = NULL;
    new_list->final_node = NULL;
    new_list->size = 0;
    return new_list;   
}

void insertStart(LinkedList* list, void* entry)
{
    ListNode *new_node = (ListNode*)malloc(sizeof(ListNode));
    new_node->data = entry;

    /*Comparison operation might not work?*/
    if (list->size == 0)
    {
        new_node->next_node = NULL;
        new_node->last_node = NULL;
        list->first_node = new_node;
        list->final_node = new_node;
    }
    else
    {
        (list->first_node)->last_node = new_node;
        new_node->next_node = list->first_node;
        new_node->last_node = NULL;
        list->first_node = new_node;
    }
    list->size += 1;
}

void* removeStart(LinkedList *list)
{
    void *return_data = NULL;
    ListNode *return_node;

    if (list->size != 0)
    {
        return_node = list->first_node;
        (list->first_node) = ((list->first_node)->next_node);
        if ((list->first_node) != NULL)
        {
            (list->first_node)->last_node = NULL;
        }
        list->size += -1;

        return_data = return_node->data;
        free(return_node);
        return_node = NULL;
    }

    return return_data;
}

void insertLast(LinkedList *list, void *entry)
{
    ListNode *new_node = (ListNode*)malloc(sizeof(ListNode));
    new_node->data = entry;

    if (list->size == 0)
    {
        new_node->next_node = NULL;
        new_node->last_node = NULL;
        list->first_node = new_node;
        list->final_node = new_node;
    }
    else
    {
        (list->final_node)->next_node = new_node;
        new_node->next_node = NULL;
        new_node->last_node = list->final_node;
        list->final_node = new_node;
    }
    list->size += 1;
}

void* removeLast(LinkedList *list)
{
    void *return_data = NULL;
    ListNode *return_node;
    
    if (list->size != 0)
    {
        return_node = list->final_node;
        (list->final_node) = ((list->final_node)->last_node);
        if ((list->final_node) != NULL)
        {
            (list->final_node)->next_node = NULL;
        }
        list->size += -1;

        return_data = return_node->data;
        free(return_node);
        return_node = NULL;
    }
    return return_data;
}

void printLinkedList(LinkedList *list, listFunc funcPtr)
{
    ListNode *current_node = list->first_node;

    while(current_node != NULL)
    {
        (*funcPtr)(current_node->data);
        current_node = current_node->next_node;
    }
}

void freeLinkedList(LinkedList *list, listFunc funcPtr)
{
    ListNode *current_node = list->first_node;
    ListNode *temp_node = NULL;

    if(list->size > 0)
    {
        while(current_node != NULL)
        {
            (*funcPtr)(current_node->data);
            current_node->data = NULL;
            free(current_node->last_node);
            current_node->last_node = NULL;
            temp_node = current_node;
            current_node = current_node->next_node;
            temp_node->next_node = NULL;
        }
        free(list->final_node);
        list->first_node = NULL;
        list->final_node = NULL;
    }
    free(list);
    list = NULL;
}
