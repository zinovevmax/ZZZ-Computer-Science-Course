#pragma once

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum { NUMCHECK = 0, REVERSE, CONVERT, STATECOUNT, END } StateName;

typedef struct State State;

typedef struct {
    State* pipeline;
    StateName cur_state;
    FILE* file;
    int reversed_number;
    int digit;
    int octal_number;
} StateMachine;

typedef struct State {
    StateName name;
    StateName (*action)(StateMachine*);
} State;