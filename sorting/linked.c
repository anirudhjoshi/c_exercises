#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sorting.h"

typedef struct node_s {

    char *key;
    int value;
    struct node_s *next, *previous;

} node;

typedef struct linked_list_s {

    node *start;
    node *end;
    unsigned int size;

} linked_list;

int insert(void *l, char *key, int value) {

    linked_list *list = (linked_list*) l;
    node *new = malloc(sizeof(node));

    if (new == NULL)
        return 0;

    new->next = 0;
    new->value = value;
    new->key = key;

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

    list->size++;

    return 1;

}

int get(void* l, char *key) {

    linked_list *list = (linked_list*) l;

    if (list == NULL)
        return -1;

    node *current;

    for (current = list->start; current->next != 0; current = current->next){

        if ( strcmp(current->key, key) )
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

        printf("Value: %i, Key: %s, Size: %i\n", current->value,
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
