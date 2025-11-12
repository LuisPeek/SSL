#include "StackModule.h"
#include <stdio.h>
#include <stdlib.h>





int main()
{
    printf("HEllo");
    StackModule* mystack = malloc(sizeof(StackModule));
    mystack->Top=0;

    StackItem* stackArray= (StackItem *) malloc(CANTIDADMAX * sizeof (StackItem));
    mystack->Stack= stackArray;
    
    int *p = mystack->Stack;
    (*p) = 10;
    mystack->Top++;
    printf("First element in stack: %d\n", (*p));

    return 0;
}
