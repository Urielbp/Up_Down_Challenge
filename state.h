//
// Created by Uriel Barbosa Pinheiro on 2019-08-24.
//

#ifndef UP_DOWN_CHALLENGE_STATE_H
#define UP_DOWN_CHALLENGE_STATE_H

#include <stdbool.h>

#define N 8
#define NFINALSTATES 7

/*
 * Each arrow is represented as a character
 * 'u' is the up arrow, 'd' is the down key and 'b' is the blank space.
 * The board is an array of 7 arrows plus the last '\0'.
 * */

typedef struct State {
    char board[N];
    int f; // g + h
    int g; // path up to here
    int h; // heuristic
    struct State *parent;
    struct State **succesors;
    int nSuccesors;
} State;

bool is_equal_state(State *s1, State *s2);
bool is_final_state(State *s, State **finalStates);
void print_state(State *s);
int heuristic1(State *s);
bool safe_state(State *initialState, State *finalState);
State ** get_valid_states(State *initialState, int *n);
bool move_from_0(State *initialState, State *finalState);
bool move_from_1(State *initialState, State *finalState);
bool move_from_2(State *initialState, State *finalState);
bool move_from_3(State *initialState, State *finalState);
bool move_from_4(State *initialState, State *finalState);
bool move_from_5(State *initialState, State *finalState);
bool move_from_6(State *initialState, State *finalState);
bool check_ancestry(State *s1, State *s2);
bool add_successor(State *s1, State *s2);
int _misplaced_arrows_top(State *s);
int _misplaced_arrows_middle(State *s, int i);
int _misplaced_arrows_bottom(State *s);
State * create_initial_state();
State ** create_final_states();

#endif //UP_DOWN_CHALLENGE_STATE_H

