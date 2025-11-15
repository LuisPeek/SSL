#include "StackModule.h"
#include <stdio.h>
#include <stdlib.h>



void inicializacionStack(StackModule* stack){
    
    while (stack->estructuraDinamica != NULL)
    {
        Dinamico* aux = stack->estructuraDinamica;
        stack->estructuraDinamica = stack->estructuraDinamica->sgte;
        free( aux);
        /* code */
    }
}
void Push(StackModule* stack , StackItem dato){
    Dinamico* nuevoNodo = malloc(sizeof(Dinamico));
    if( nuevoNodo == NULL) {
        printf("Error de memoria\n");
        return;
    }
        nuevoNodo->item= dato;
        nuevoNodo->sgte = stack->estructuraDinamica;
        stack->estructuraDinamica = nuevoNodo;
    
}
StackItem Pop(StackModule* stack){
    if(IsEmpty(stack)){
        printf("estaVacia");
        return -1;
    }else{
        StackItem valor ;
        Dinamico* nodo = stack->estructuraDinamica;
        valor = nodo->item;

        stack->estructuraDinamica= nodo->sgte;
        free(nodo);
        return valor;     
    }
}
int IsEmpty( StackModule* stack ){
    return stack->estructuraDinamica == NULL ? 1: 0;
}
int IsFull(StackModule* stack){
    return 0;
}

void mostrarLista(StackModule* stack) {
    if(IsEmpty(stack)){
        printf("Esta Vacia \n");
    }
        Dinamico* puntero=  stack->estructuraDinamica;
        printf("Contenido de la pila\n");
        while (puntero != NULL)
        {
            printf("valor :%d\n",puntero->item);
            puntero = puntero->sgte;
        }
        
    
}
int main(){
    StackModule stack;

    inicializacionStack(&stack);

    Push(&stack, 10);
    Push(&stack, 20);
    Push(&stack, 30);

    mostrarLista(&stack);

    printf("Pop: %d\n", Pop(&stack));
    printf("Pop: %d\n", Pop(&stack));

    mostrarLista(&stack);
}
