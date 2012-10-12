#include <stdio.h>
#include <stdlib.h>

#include "sorting.h"

typedef struct node_s {

    int value;
    struct node_s *next, *previous;

} node;


typedef struct linked_list_s {

    node *start;
    node *end;
    unsigned int size;

} linked_list;

int insert(void *l, int value) {

    linked_list *list = (linked_list*) l;
    node *new = malloc(sizeof(node));

    if (new == NULL)
        return 0;

    new->next = 0;
    new->previous = list->end;
    new->value = value;

    if (list->end->next)
        list->end->next = new;

    list->end = new;

    return 1;

}

void* initialise(){

    linked_list *list = malloc(sizeof(linked_list));

    if (list == NULL)
        return NULL;

    list->size = 0;
    list->start = 0;
    list->end = 0;

    return (void*) list;

}
