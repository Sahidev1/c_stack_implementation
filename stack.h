#include "node.h"

#ifndef STACK_H
#define STACK_H

typedef enum {false, true} boolean;

typedef struct Stack
{
    node* first;
    int size;
    void (*push)(struct Stack* this_stack, int data);
    int (*pop)(struct Stack* this_stack); 
}stack;

typedef struct Stack_iterator {
    node* current;
    boolean (*has_next)(struct Stack_iterator* iter);
    void (*goto_next)(struct Stack_iterator* iter);
}stack_iterator;

stack* stack_constructor ();

stack_iterator* stack_iter_constructor(stack* stck);

void stack_iter_destructor (stack_iterator* iter);

void stack_destructor (stack* stck);


#endif