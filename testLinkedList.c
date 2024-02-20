#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linkedlist.h"

void print_with_string(void *data)
{
    char *a = (char*)data;
    printf("%s\n",a);
}

int main(int argc, char** argv)
{
    LinkedList *list;
    void *data;
    char items[5][10] = {"apple","banana","cherry","dango","eclaire"};
    list = createLinkedList();

    printf("inserting start\n");
    insertStart(list, items[1]);
    insertStart(list, items[2]);
    printf("inserting last\n");
    insertLast(list, items[3]);
    insertLast(list, items[4]);
    printLinkedList(list, &print_with_string);
    printf("removing start\n");
    data = removeStart(list);
    printf("%s\n",(char*)data);
    printf("removing start\n");
    data = removeStart(list);
    printf("%s\n",(char*)data);
    data = removeLast(list);
    printf("removing last\n");
    printf("%s\n",(char*)data);
    insertLast(list, items[0]);
    printLinkedList(list, &print_with_string);
    freeLinkedList(list, &print_with_string);
    return 0;
}