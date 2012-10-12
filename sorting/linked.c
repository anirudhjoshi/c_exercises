#include <stdio.h>
#include <stdlib.h>

#include "sorting.h"

typedef struct node_s {

    int key;
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
    new->value = value;

    if (list->end) {

        new->previous = list->end;
        list->end->next = new;
        list->end = new;

    } else if (list->start){

        new->previous = list->start;
        list->start->next = new;
        list->end = new;

    } else {

        new->previous = 0;
        list->start = new;

    }

    new->key = list->size;
    list->size++;

    return 1;

}

int get(void* l, int key) {

    linked_list *list = (linked_list*) l;

    if (list == NULL)
        return -1;

    node *current;

    for (current = list->start; current->next != 0; current = current->next){

        if (current->key == key)
            return current->value;

    }

    return -1;

}

int put(void* l, int key, int value){

    linked_list *list = (linked_list*) l;
    node *new = malloc(sizeof(node));

    if (new == NULL)
        return -1;

    if (key == 0){

        list->start->previous = new;
        new->next = list->start;

        list->start = new;

    }

    if (key = list->size){


    }

}

void printList(void* l){

    linked_list *list = (linked_list*) l;

    if (list == NULL)
        return;

    node *current;

    for (current = list->start; current != 0; current = current->next){

        printf("Value: %i, Key: %i, Size: %i\n", current->value,
        current->key, list->size);

    }

    return;
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
