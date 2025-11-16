#include "StackModule.h"
#include <stdio.h>
#include <stdlib.h>
#include "assert.h"

void testStackInicializacion() {
    StackModule pila ;
    pila.estructuraDinamica = NULL;
    inicializacionStack(&pila);
    assert(!IsFull(&pila));
}
void testStackPushPop() {
    StackModule pila;
    pila.estructuraDinamica = NULL;
    inicializacionStack(&pila);
    Push(&pila, 15); 
    assert(Pop(&pila) == 15);
    assert(IsEmpty(&pila));
}
void testStackFull(){
    StackModule pila;
    pila.estructuraDinamica = NULL;
    inicializacionStack(&pila);
    Push(&pila,1);
    Push(&pila,2);
    Push(&pila,3);
    Push(&pila,4);
    if(pila.estructuraDinamica != NULL){ 
        /// test dinamico 
        assert(!IsFull(&pila));
    }else{
        assert(IsFull(&pila));
    }

}

void testStackDinamico(){
    StackModule pila ;
    pila.estructuraDinamica = NULL;
    inicializacionStack(&pila);
    Push(&pila,400);
    Push(&pila,300);
    Push(&pila,200);
    Push(&pila,100);
    Push(&pila,400);
    Push(&pila,300);
    Push(&pila,200);
    Push(&pila,100);
    if(pila.estructuraDinamica !=NULL){ /// test dinamico 
        assert(Pop(&pila) == 100);
        assert(Pop(&pila) == 200);
        assert(Pop(&pila) == 300);
        assert(Pop(&pila) == 400);
        assert(Pop(&pila) == 100);
        assert(Pop(&pila) == 200);
        assert(Pop(&pila) == 300);
        assert(Pop(&pila) == 400);
    }
}
int main(){
        printf("TEST DE INICIALIZACION DE LA PILA\n");
        testStackInicializacion();
        printf("\n");
        printf("TEST DE PUSH Y POP\n");
        testStackPushPop();
        printf("\n");
        printf("TEST DE STTACK FULL\n");
        testStackFull();
        printf("\n");
        printf("TEST DE STTACK DINAMICO\n");
        testStackDinamico();
        printf("PASARON TODOS LOS TEST\n");

    return 0;
}
// TERMINADO