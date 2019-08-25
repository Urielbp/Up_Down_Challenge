//
// Created by Uriel Barbosa Pinheiro on 2019-08-24.
//

#include "state.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool is_equal_state(State *s1, State *s2) {
    return (strcmp(s1->board, s2->board) == 0) ? true : false;
    /*
    for (int i = 0; i < N - 1; i++) {
        if (s1->board[i] != s2->board[i]) {
            return false;
        }
    }
    return true;
    */
}

bool is_final_state(State *s, State **finalStates) {
    for (int i = 0; i < NFINALSTATES; i++) {
        if (is_equal_state(s, finalStates[i]) == true) {
            return true;
        }
    }
    return false;
}

void print_state(State *s) {
    printf("\n");
    for (int i = 0; i < N - 1; i++) {
        printf("[%c]\n", s->board[i]);
    }
}
int heuristic1(State *s) {
    int heuristicValue = 0;
    if (s == NULL) {
        return -1;
    }
    // Return how many misplaced arrows are in between
    heuristicValue += _misplaced_arrows_top(s);
    for (int i = 1; i < N - 2; i++) {
        heuristicValue += _misplaced_arrows_middle(s, i);
    }
    heuristicValue += _misplaced_arrows_bottom(s);

    return heuristicValue;
}
bool safe_state(State *initialState, State *finalState) {
    return (strcmp(initialState->board, finalState->board) != 0);
}

State ** get_valid_states(State *initialState, int *n) {
    State *s1,*s2,*s3,*s4,*s5,*s6,*s7;
    State **states = (State **) calloc(NFINALSTATES, sizeof(State *));
    *n = 0;

    s1 = (State*) calloc(1, sizeof(State));
    s2 = (State*) calloc(1, sizeof(State));
    s3 = (State*) calloc(1, sizeof(State));
    s4 = (State*) calloc(1, sizeof(State));
    s5 = (State*) calloc(1, sizeof(State));
    s6 = (State*) calloc(1, sizeof(State));
    s7 = (State*) calloc(1, sizeof(State));

    if(states == NULL|| s1 == NULL || s2 == NULL || s3 == NULL || s4 == NULL || s5 == NULL || s6 == NULL  || s7 == NULL) {
        return  NULL;
    }

    if(move_from_0(initialState, s1) == true) {
        states[*n] = s1;
        *n += 1;
    }
    else {
        free(s1);
    }
    if(move_from_1(initialState, s2) == true) {
        states[*n] = s2;
        *n += 1;
    }
    else {
        free(s2);
    }

    if(move_from_2(initialState, s3) == true) {
        states[*n] = s3;
        *n += 1;
    }
    else {
        free(s3);
    }

    if(move_from_3(initialState, s4) == true) {
        states[*n] = s4;
        *n += 1;
    }
    else {
        free(s4);
    }

    if(move_from_4(initialState, s5) == true) {
        states[*n] = s5;
        *n += 1;
    }
    else {
        free(s5);
    }

    if(move_from_5(initialState, s6) == true) {
        states[*n] = s6;
        *n += 1;
    }
    else {
        free(s6);
    }

    if(move_from_6(initialState, s7) == true) {
        states[*n] = s7;
        *n += 1;
    }
    else {
        free(s7);
    }
    states = (State **) realloc(states, (*n * sizeof(State *)));
    return states;
}

bool move_from_0(State *initialState, State *finalState) {
    if (initialState->board[0] == 'd' && initialState->board[1] == 'b') {
        *finalState = *initialState;
        finalState->board[0] = 'b';
        finalState->board[1] = 'd';
        return true;
    }
    else if (initialState->board[0] == 'd' && initialState->board[1] == 'u' && initialState->board[2] == 'b') {
        finalState->board[0] = 'b';
        finalState->board[2] = 'd';
        return true;
    }
    else {
        return false;
    }
}
bool move_from_1(State *initialState, State *finalState) {
    *finalState = *initialState;
    if (initialState->board[0] == 'b' && initialState->board[1] == 'u') {
        finalState->board[0] = 'u';
        finalState->board[1] = 'b';
        return true;
    }
    else if(initialState->board[1] == 'd' && initialState->board[2] == 'b') {
        finalState->board[1] = 'b';
        finalState->board[2] = 'd';
        return true;
    }
    else if (initialState->board[1] == 'd' && initialState->board[2] == 'u' && initialState->board[3] == 'b') {
        finalState->board[1] = 'b';
        finalState->board[3] = 'd';
        return true;
    }
    else {
        return false;
    }
}

bool move_from_2(State *initialState, State *finalState) {
    *finalState = *initialState;
    if (initialState->board[1] == 'b' && initialState->board[2] == 'u') {
        finalState->board[1] = 'u';
        finalState->board[2] = 'b';
        return true;
    }
    else if(initialState->board[2] == 'd' && initialState->board[3] == 'b') {
        finalState->board[2] = 'b';
        finalState->board[3] = 'd';
        return true;
    }
    else if (initialState->board[0] == 'b' && initialState->board[1] == 'd' && initialState->board[2] == 'u') {
        finalState->board[0] = 'u';
        finalState->board[2] = 'b';
        return true;
    }
    else if (initialState->board[2] == 'd' && initialState->board[3] == 'u' && initialState->board[4] == 'b') {
        finalState->board[2] = 'b';
        finalState->board[4] = 'd';
        return true;
    }
    else {
        return false;
    }
}
bool move_from_3(State *initialState, State *finalState) {
    *finalState = *initialState;
    if (initialState->board[2] == 'b' && initialState->board[3] == 'u') {
        finalState->board[2] = 'u';
        finalState->board[3] = 'b';
        return true;
    }
    else if(initialState->board[3] == 'd' && initialState->board[4] == 'b') {
        finalState->board[3] = 'b';
        finalState->board[4] = 'd';
        return true;
    }
    else if (initialState->board[1] == 'b' && initialState->board[2] == 'd' && initialState->board[3] == 'u') {
        finalState->board[1] = 'u';
        finalState->board[3] = 'b';
        return true;
    }
    else if (initialState->board[3] == 'd' && initialState->board[4] == 'u' && initialState->board[5] == 'b') {
        finalState->board[3] = 'b';
        finalState->board[5] = 'd';
        return true;
    }
    else {
        return false;
    }
}
bool move_from_4(State *initialState, State *finalState) {
    *finalState = *initialState;
    if (initialState->board[3] == 'b' && initialState->board[4] == 'u') {
        finalState->board[3] = 'u';
        finalState->board[4] = 'b';
        return true;
    }
    else if(initialState->board[4] == 'd' && initialState->board[5] == 'b') {
        finalState->board[4] = 'b';
        finalState->board[5] = 'd';
        return true;
    }
    else if (initialState->board[2] == 'b' && initialState->board[3] == 'd' && initialState->board[4] == 'u') {
        finalState->board[2] = 'u';
        finalState->board[4] = 'b';
        return true;
    }
    else if (initialState->board[4] == 'd' && initialState->board[5] == 'u' && initialState->board[6] == 'b') {
        finalState->board[4] = 'b';
        finalState->board[6] = 'd';
        return true;
    }
    else {
        return false;
    }
}
bool move_from_5(State *initialState, State *finalState) {
    *finalState = *initialState;
    if (initialState->board[4] == 'b' && initialState->board[5] == 'u') {
        finalState->board[4] = 'u';
        finalState->board[5] = 'b';
        return true;
    }
    else if(initialState->board[5] == 'd' && initialState->board[6] == 'b') {
        finalState->board[5] = 'b';
        finalState->board[6] = 'd';
        return true;
    }
    else if (initialState->board[3] == 'b' && initialState->board[4] == 'd' && initialState->board[5] == 'u') {
        finalState->board[3] = 'u';
        finalState->board[5] = 'b';
        return true;
    }
    else {
        return false;
    }
}
bool move_from_6(State *initialState, State *finalState) {
    if (initialState->board[5] == 'b' && initialState->board[6] == 'u') {
        *finalState = *initialState;
        finalState->board[5] = 'u';
        finalState->board[6] = 'b';
        return true;
    }
    else if (initialState->board[4] == 'b' && initialState->board[5] == 'd' && initialState->board[6] == 'u') {
        finalState->board[4] = 'u';
        finalState->board[6] = 'b';
        return true;
    }
    else {
        return false;
    }
}


bool check_ancestry(State *s1, State *s2) {
    if(s2->parent == NULL){
        return false;
    }

    if(is_equal_state(s2->parent, s1) == true) {
        return true;
    }
    return (check_ancestry(s1, s2->parent));
}
bool add_successor(State *s1, State *s2) {
    State **aux;

    if(s2->nSuccesors == 0) {
        s2->succesors = (State **) malloc(1 * sizeof(State *));
        if(s2->succesors == NULL){
            return false;
        }
        s2->succesors[0] = s1;
        s2->nSuccesors = 1;
        return true;
    }
    else {
        aux = (State **) malloc(s2->nSuccesors * sizeof(State *));
        if(aux == NULL) {
            return false;
        }
        //*aux = *s2->sucesores;
        memcpy(aux, s2->succesors, s2->nSuccesors * sizeof(State *));
        s2->succesors = (State **) realloc(s2->succesors, (s2->nSuccesors + 1) * sizeof(State *));
        if (s2->succesors == NULL) {
            return false;
        }

        memcpy(s2->succesors, aux, s2->nSuccesors * sizeof(State *));
//        for (i = 0; i < s2->nSucesores; i++) {
//            s2->sucesores[i] = aux[i];
//        }
        s2->succesors[s2->nSuccesors] = s1;
        s2->nSuccesors += 1;
        free(aux);
        return true;
    }
}

int _misplaced_arrows_top(State *s) {
    char comparedArrow = s->board[0];
    int value = 0;
    for (int i = 1; i < N - 1; i++) {
        if (s->board[i] != comparedArrow && s->board[i] != 'b') {
            value++;
        }
    }
    return  value;
}

int _misplaced_arrows_middle(State *s, int i) {
    char comparedArrow = s->board[i];
    int value = 0;
    // Compare with all above the "comparedArrow"
    for (int j = 0; j < i; j++) {
        if (s->board[j] != comparedArrow && s->board[j] != 'b') {
            value++;
        }
    }
    // Compare with all below the "comparedArrow"
    for (int j = i; j < N - 1; j++) {
        if (s->board[j] != comparedArrow && s->board[j] != 'b') {
            value++;
        }
    }
    return value;
}

int _misplaced_arrows_bottom(State *s) {
    char comparedArrow = s->board[N - 2];
    int value = 0;
    for (int j = 0; j < N - 1; j++) {
        if (s->board[j] != comparedArrow && s->board[j] != 'b') {
            value++;
        }
    }
    return value;
}

State * create_initial_state() {
    State *s = (State *) calloc(1, sizeof(State));
    s->board[0] = 'd';
    s->board[1] = 'd';
    s->board[2] = 'd';
    s->board[3] = 'b';
    s->board[4] = 'u';
    s->board[5] = 'u';
    s->board[6] = 'u';
    return s;
}
State ** create_final_states() {
    State *s1,*s2,*s3,*s4,*s5,*s6,*s7;
    State **states = (State **) calloc(NFINALSTATES, sizeof(State *));

    s1 = (State*) calloc(1, sizeof(State));
    s2 = (State*) calloc(1, sizeof(State));
    s3 = (State*) calloc(1, sizeof(State));
    s4 = (State*) calloc(1, sizeof(State));
    s5 = (State*) calloc(1, sizeof(State));
    s6 = (State*) calloc(1, sizeof(State));
    s7 = (State*) calloc(1, sizeof(State));

    if(states == NULL|| s1 == NULL || s2 == NULL || s3 == NULL || s4 == NULL || s5 == NULL || s6 == NULL  || s7 == NULL) {
        return  NULL;
    }
    states[0] = s1;
    states[1] = s2;
    states[2] = s3;
    states[3] = s4;
    states[4] = s5;
    states[5] = s6;
    states[6] = s7;

    s1->board[0] = 'b';
    s1->board[1] = 'u';
    s1->board[2] = 'u';
    s1->board[3] = 'u';
    s1->board[4] = 'd';
    s1->board[5] = 'd';
    s1->board[6] = 'd';

    s2->board[0] = 'u';
    s2->board[1] = 'b';
    s2->board[2] = 'u';
    s2->board[3] = 'u';
    s2->board[4] = 'd';
    s2->board[5] = 'd';
    s2->board[6] = 'd';

    s3->board[0] = 'u';
    s3->board[1] = 'u';
    s3->board[2] = 'b';
    s3->board[3] = 'u';
    s3->board[4] = 'd';
    s3->board[5] = 'd';
    s3->board[6] = 'd';

    s4->board[0] = 'u';
    s4->board[1] = 'u';
    s4->board[2] = 'u';
    s4->board[3] = 'b';
    s4->board[4] = 'd';
    s4->board[5] = 'd';
    s4->board[6] = 'd';

    s5->board[0] = 'u';
    s5->board[1] = 'u';
    s5->board[2] = 'u';
    s5->board[3] = 'd';
    s5->board[4] = 'b';
    s5->board[5] = 'd';
    s5->board[6] = 'd';

    s6->board[0] = 'u';
    s6->board[1] = 'u';
    s6->board[2] = 'u';
    s6->board[3] = 'd';
    s6->board[4] = 'd';
    s6->board[5] = 'b';
    s6->board[6] = 'd';


    s7->board[0] = 'u';
    s7->board[1] = 'u';
    s7->board[2] = 'u';
    s7->board[3] = 'd';
    s7->board[4] = 'd';
    s7->board[5] = 'd';
    s7->board[6] = 'b';

    return states;
}

