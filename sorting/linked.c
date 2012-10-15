#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sorting.h"

typedef struct node_s {

    record* data;
    struct node_s *next, *previous;

} node;

typedef struct linked_list_s {

    node *start;
    node *end;
    unsigned int size;

} linked_list;

void deleteNode(linked_list*, node*);

int put(void *l, record *data) {

    linked_list *list = (linked_list*) l;
    node *new = malloc(sizeof(node));

    if (new == NULL)
        return 0;

    new->next = 0;
    new->data = data;

    if (list->end != 0) {

        list->end->next = new;
        new->previous = list->end;

        list->end = new;

    } else if (list->start != 0) {

        list->start->next = new;
        new->previous = list->start;

        list->end = new;

    } else {

        new->previous = 0;
        list->start = new;

    }

    list->size++;

    return 1;

}

record* get(void* l, char *key) {

    linked_list *list = (linked_list*) l;

    if (list == NULL)
        return NULL;

    node *current;

    for (current = list->start; current->next != 0; current = current->next){

        if ( strcmp(current->data->key, key) == 0 ){

            return current->data;

        }

    }

    if ( strcmp(current->data->key, key) == 0 ){

            return current->data;

    }

    return NULL;

}

int del(void* l, char* key){

    linked_list *list = (linked_list*) l;

    if (list == NULL)
        return 0;

    node *current;

    for (current = list->start; current->next != 0; current = current->next){

        if ( strcmp(current->data->key, key) == 0 ) {

            deleteNode(list, current);
            return 1;

        }

    }

    if ( strcmp(current->data->key, key) == 0 ) {

        deleteNode(list, current);
        return 1;

    }

    return 0;

}

void deleteNode(linked_list* list, node* current) {

    node* previous = current->previous;
    node* next = current->next;

    if (previous == 0) {

        next->previous = 0;
        list->start = next;

    } else {

        previous->next = next;

    }


    if (next == 0) {

        previous->next = 0;
        list->end = previous;

    } else {

        previous->next = next;

    }

    list->size -= 1;

    free(current->data);
    free(current);

}

void printList(void* l){

    linked_list *list = (linked_list*) l;

    if (list == NULL)
        return;

    node *current;

    for (current = list->start; current != 0; current = current->next){

        printf("Value: %s, Key: %s, Size: %i\n", current->data->value,
        current->data->key, list->size);

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
