#include "node.h"
#include <stdlib.h>

node* node_constructor (int data){
    node* n = (node*) malloc(sizeof(node));
    n->data = data;
    n->next = NULL;
    return n;
}

void destroy_node (node* n){
    free(n);
}

void link_nodes (node* source_node, node* next_node){
    source_node->next = next_node;
}
