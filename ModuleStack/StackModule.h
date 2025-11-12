/*
a. Push.
b. Pop.
c. IsEmpty.
d. IsFull.
*/
#ifndef STACKMODULE_H
#define STACKMODULE_H

#define CANTIDADMAX 4
typedef int StackItem;


typedef struct StackModule{
    StackItem* Stack;
    int Top;
}StackModule;


void  Push (StackModule* st, StackItem item);

void Pop (StackModule* st);

int IsEmpty (StackModule* st);
int IsFull (StackModule* st);
#endif 