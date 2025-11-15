#include "StackModule.h"
#include <stdio.h>
#include <stdlib.h>



void inicializacionStack(StackModule* mystack){
    mystack = malloc(sizeof(StackModule));
    mystack->Top=0;

    StackItem* stackArray= (StackItem *) malloc(CANTIDADMAX * sizeof (StackItem));
    mystack->Stack= stackArray;
    StackItem *p = mystack->Stack;
    
    (*p) = 10;
    mystack->Top++;
}

void Push(StackModule* stackModule, StackItem item){
    StackItem *p = stackModule->Stack;
    if (IsFull(stackModule)){
        printf("Stack Overflow\n");
    }else
    {
        *(p + stackModule->Top) = item;
        stackModule->Top++;
    }
    
}

static void mostraStackContinuo(StackModule* stackModule){
    int *p= stackModule->Stack;
    for (int i = 0; i < stackModule->Top; i++)
    {
       printf("Element %d:%d\n",i, *(p+i));
    }
    
}

int IsFull(StackModule* StackModule){
    return StackModule->Top >= CANTIDADMAX ? 1: 0;
}
void Pop(StackModule* stackModule){
    StackItem *p = stackModule->Stack;
    if(IsEmpty(stackModule)){
        printf("EL Stack esta vacio\n");
    }else{
        printf("top antes de pop %d\n",stackModule->Top);
        printf("Elemento %d eliminado \n",(*(p + stackModule->Top-1)));
        *(p + stackModule ->Top) = 0;
        stackModule->Top--;
    }
}

int IsEmpty(StackModule* stackModule){
    return stackModule->Top <= 0? 1:0;
}

