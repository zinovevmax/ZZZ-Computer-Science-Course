#pragma once

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum {
    START = 0,
    NUMCHECK,
    CONVERT,
    // Add new states here
    STATECOUNT,
    END
} StateName;

typedef struct State State;

typedef struct {
    State* pipeline;
    StateName cur_state;
    int step;
    FILE* file;
    int celsius;
    int num_is_found;
    double fahrenheit;
} StateMachine;

typedef struct State {
    StateName name;
    StateName (*action)(StateMachine*);
} State;