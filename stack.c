#include "stack.h"
#include "node.h"
#include <stdlib.h>

void push (stack* this_stack, int data){
    node* n = (node*) malloc (sizeof(node));
    n->data = data;
    n->next = NULL;
    this_stack->size++;
    if (this_stack->first == NULL){
        this_stack->first = n;
        return;
    }

    n->next = this_stack->first;
    this_stack->first = n;
}

int pop (stack* this_stack){
    if (this_stack->first == NULL){
        return -1;
    }
    int return_data = this_stack->first->data;
    node* tmp_ptr = this_stack->first;
    this_stack->first = this_stack->first->next;
    destroy_node (tmp_ptr);
    this_stack->size--;
    return return_data;
}


void stack_destructor (stack* stck){
    int pop_val;
    while (stck->size > 0){
        pop_val = stck->pop(stck);
    }
    free (stck);
}

boolean has_next(stack_iterator* iter){
    return iter->current != NULL;
}


void goto_next (stack_iterator* iter){
    iter->current = iter->current->next;
}

void stack_iter_destructor (stack_iterator* iter){
    free (iter);
}

stack_iterator* stack_iter_constructor(stack* stck){
    stack_iterator* iter = (stack_iterator*) malloc (sizeof(stack_iterator));
    iter->current = stck->first;
    iter->has_next = has_next;
    iter->goto_next = goto_next;
}

stack* stack_constructor (){
    stack* stck = (stack*) malloc (sizeof(stack));
    stck->size = 0;
    stck->first = NULL;
    stck->push = push;
    stck->pop = pop;
    return stck;
}
