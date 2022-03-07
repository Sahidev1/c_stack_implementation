#ifndef NODE_H
#define NODE_H

typedef struct Node
{
    int data;
    struct Node *next;
}node;

node* node_constructor (int data);
void link_nodes (node* source_node, node* next_node);
void destroy_node (node* n);

#endif