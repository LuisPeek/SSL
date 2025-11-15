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

typedef struct Statico{
    StackItem* Stack;
    int Top;
}Statico;


typedef struct Dinamico {
    StackItem item;
    struct Dinamico* sgte;
}Dinamico;



typedef struct StackModule{
    Statico estructuraStactica;
    Dinamico* estructuraDinamica;
}StackModule;


void  Push (StackModule* st, StackItem item);
StackItem Pop (StackModule* st);
int IsEmpty (StackModule* st);
int IsFull (StackModule* st);

#endif 