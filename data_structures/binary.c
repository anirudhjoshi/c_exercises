#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "sorting.h"

typedef struct node_s {

    record* data;
    struct node_s *left, *right;

} node;

typedef struct bst_tree_s {

    node* root;
    int size;

} bst_tree;


void* initialize() {

    bst_tree* tree = malloc(sizeof(bst_tree));

    tree->root = malloc(sizeof(node));

    tree->root->left = 0;
    tree->root->right = 0;
    tree->root->data = 0;

    return (void*) tree;

}

int put(void* t, record* data) {




}
