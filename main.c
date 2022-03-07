/** Written by Sahidev1 **/

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "node.h"

int main(void) {
    stack* stack = stack_constructor();
    int push_val;
    int pop_val;
    int prints;
    while (true){
        int choice;
        printf ("1. push \n2. pop \n3. iterate \n");
        scanf ("%d", &choice);
        switch (choice)
        {
        case 1:
            printf ("Enter value to push: \n");
            scanf ("%d", &push_val);
            stack->push(stack, push_val);
            break;
        case 2:
            pop_val = stack->pop(stack);
            printf ("Poped value: %d \n", pop_val);
            break;
        case 3:
            prints = 0;
            stack_iterator* iter = stack_iter_constructor(stack);
            while (iter->has_next(iter)){
                printf ("%d ,", iter->current->data);
                prints++;
                if (prints > 0 && prints % 10 == 0){
                    printf ("/n");
                }
                iter->goto_next(iter);
            }
            printf ("\n");
            stack_iter_destructor (iter);
            break;
        default:
            break;
        }
    }
    stack_destructor(stack);

    return 0;
}