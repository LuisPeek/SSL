#include "StackModule.h"
#include <stdio.h>
#include <stdlib.h>
#include "assert.h"


void inicializacionStack(StackModule* mystack){
    mystack->estructuraStactica.Top=0;

    StackItem* stackArray= (StackItem *) malloc(CANTIDADMAX * sizeof (StackItem));
    mystack->estructuraStactica.Stack= stackArray;
}

void Push(StackModule* stackModule, StackItem item){
    StackItem *p = stackModule->estructuraStactica.Stack;
    if (IsFull(stackModule)){
        printf("Stack Overflow\n");
    }else
    {
        *(p + stackModule->estructuraStactica.Top) = item;
        stackModule->estructuraStactica.Top++;

    }
    
}

static void mostraStackContinuo(StackModule* stackModule){
    int *p= stackModule->estructuraStactica.Stack;
    for (int i = 0; i < stackModule->estructuraStactica.Top; i++)
    {
       printf("Element %d:%d\n",i, *(p+i));
    }
    
}

int IsFull(StackModule* StackModule){
    return StackModule->estructuraStactica.Top >= CANTIDADMAX ? 1: 0;
}

StackItem Pop(StackModule* stackModule){
    StackItem *p = stackModule->estructuraStactica.Stack;
    if(IsEmpty(stackModule)){
        printf("EL Stack esta vacio\n");
    }else{
        printf("top antes de pop %d\n",stackModule->estructuraStactica.Top);
        printf("Elemento %d eliminado \n",(*(p + stackModule->estructuraStactica.Top-1)));
        
        *(p + stackModule ->estructuraStactica.Top) = 0;
        stackModule->estructuraStactica.Top--;

        return (*(p + stackModule->estructuraStactica.Top));
    }
}

int IsEmpty(StackModule* stackModule){
    return stackModule->estructuraStactica.Top <= 0? 1:0;
}
