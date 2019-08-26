//
// Created by Uriel Barbosa Pinheiro on 2019-08-24.
//

#include "heap.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "aStar.h"

bool aStar(){
    int solutionLength = -1;
    bool alreadyInClosed = false, alreadyInOpen = false;
    State *initialState, **finalStates, *outputState;
    State **h;
    int *nNodesinExpansion;
    int i, j,nClosed = 0, openPosition, closedPosition;
    Heap open;
    State **closed;
    HeapElement auxHeap, aux2Heap;
    State *auxState;

    closed = (State **) calloc(MAXIMUMOPENCLOSED, sizeof(State *));
    initialState = create_initial_state();
    finalStates = create_final_states();
    nNodesinExpansion = (int *) malloc(1 * sizeof(int));

    if(closed == NULL || initialState == NULL || finalStates == NULL || nNodesinExpansion == NULL) {
        fprintf(stderr,"Error in memory alloc\n");
        return false;
    }

    auxState = (State *) malloc(1 * sizeof(State));
    if(auxState == NULL) {
        return  false;
    }

    initialState->h = heuristic1(initialState);                     //TODO: Change heuristic
    initialState->g = 0;
    initialState->f = initialState->g + initialState->h;
    initialState->nSuccesors = 0;
    auxHeap.key = initialState->f;
    auxHeap.value = initialState;

    heap_init(&open);
    heap_insert(auxHeap, &open);

    while(1){
        //Si la lista de open está vacía, devuelve fallo
        if(heap_is_empty(&open) == true) {
            // Dead end
            printf("Dead end reached, the final states could not be reached from the initial state");
            return false;
        }
        //Si hubo algún error al eliminar el nodo actual, devolvemos fallo
        if(heap_delete(&auxHeap, &open) == false) {
            return false;
        }
        auxState = auxHeap.value;
        //Si el nodo actual es el nodo final, tenemos la solución
        if(is_final_state(auxState, finalStates) == true) {
            printf("Solución hallada.\n");

            outputState = (State *) malloc((auxState->g + 1) * sizeof(State));
            if (outputState == NULL) {
                return false;
            }
            outputState[0] = *auxState;
            solutionLength = 0;
            auxState = outputState;
            while(auxState != NULL){
                solutionLength += 1;
                outputState[solutionLength] = *auxState;
                auxState = auxState->parent;
            }

            printf("Solución con %d movimientos.", solutionLength - 1);
            for (i = solutionLength ; i > 0; i--) {
                printf("\n");
                print_state(&outputState[i]);
            }
//            TODO: Para imprimir la solución

            free(initialState);
            free(finalStates);
            free(closed);

            return true;
        }

        // Expandimos el nodo actual
        closed[nClosed] = auxState;

        nClosed += 1;
        h = get_valid_states(auxState, nNodesinExpansion);


        for (i = 0; i < *nNodesinExpansion; i++) {
            // Comprobamos si el nodo sucesor no es ascendiente de n
            if(check_ancestry(h[i], auxState) == false) {
                openPosition = 0;
                closedPosition = 0;
                //Añadimos el nodo de M como sucesor de n
                h[i]->nSuccesors = 0;
                if(add_successor(h[i], auxState) == false) {
                    return false;
                }
                alreadyInOpen = false;
                alreadyInClosed = false;
                h[i]->g = auxState->g + 1;
                h[i]->h = heuristic1(h[i]);                     //TODO: Cambiar heurísitica
                h[i]->f = h[i]->g + h[i]->h;

                //Buscamos por el elemento en open
                for (j = 0; j < open.size; j++) {
                    //Recorremos la lista de open
                    if (is_equal_state(open.element[j + 1].value, h[i])) {
                        //Si el sucesor ya está en la lista de open
                        alreadyInOpen = true;
                        openPosition = j + 1;
                        break;
                    }
                }
                //Buscamos por el elemento en closed
                for (j = 0; j < nClosed; j++) {
                    if (is_equal_state(closed[j], h[i])) {
                        alreadyInClosed = true;
                        closedPosition = j;
                        break;
                    }
                }

                if(alreadyInOpen == true) {
                    if(h[i]->f > ((open.element[openPosition].value->f) )) {
                        head_decrease_key(open.element[openPosition], h[i]->f, &open);
                        h[i]->parent = auxState;
                    }
                }
                else if (alreadyInClosed == true) {
                    if(h[i]->f > ((closed[closedPosition]->f) )) {
                        closed[closedPosition]->f = h[i]->f;
                        h[i]->parent = auxState;
                    }

                    if((h[i]->f) < (closed[closedPosition]->f)) {
                        //El camino por el nodo actual es mejor
                        h[i]->succesors = (State **) malloc((closed[closedPosition]->nSuccesors) * sizeof(State *));
                        h[i]->nSuccesors = closed[closedPosition]->succesors;
                        for (j = 0; j < closed[closedPosition]->nSuccesors; j++) {
                            //h[i]->sucesores[j]->parent = closed[closedPosition]->parent;
                            closed[closedPosition]->succesors[j]->parent = h[i];
                        }
                    }
                }
                else {
                    //Ni en open ni closed
                    h[i]->parent = auxState;
                    aux2Heap.value = h[i];
                    aux2Heap.key = h[i]->f;
                    heap_insert(aux2Heap, &open);
                }
            }
        }
    }
}