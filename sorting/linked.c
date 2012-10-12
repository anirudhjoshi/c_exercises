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

    for (current = list->start; current->next != 0; current = current->next){

        printf("%i\n", current->value);

    }

    return (void*) list;

}
