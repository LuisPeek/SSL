#include "StackModule.h"
#include <stdio.h>
#include <stdlib.h>
#include "assert.h"


void inicializacionStack(StackModule* stack){
    printf("HOAL\n");
    while (stack->estructuraDinamica != NULL)
    {
        Dinamico* aux = stack->estructuraDinamica;
        stack->estructuraDinamica = stack->estructuraDinamica->sgte;
        free(aux);
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
