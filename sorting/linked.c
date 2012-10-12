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

void* create(int *data, int size) {

    int i;

    linked_list *list = malloc(sizeof(list));
    list->start = list->end = 0;

    node *current = malloc(sizeof(node));
    node *next = malloc(sizeof(node));

    current->previous = 0;
    list->start = current;

    for (i = 0; i < size; i++) {

        current->value = data[i];
        current->next = next;
        next->previous = current;

        current = next;

        next = malloc(sizeof(node));

    }

    current->next = 0;
    list->end = current;
    list->size = size;

    return (void*) list;

}

int insert(void *l, int value) {
    linked_list *list = (linked_list*) l;
    node *new = malloc(sizeof(node));

    if (new == NULL)
        return 0;

    new->next = 0;
    new->previous = list->end;
    new->value = value;
    list->end->next = new;
    list->end = new;

    return 1;

}

void* initialise(){

    linked_list *list = malloc(sizeof(linked_list));

    list->size = 0;
    list->start = 0;
    list->end = 0;

    return (void*) list;

}
