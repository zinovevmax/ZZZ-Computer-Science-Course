#pragma once

#include "stdlib.h"
#include <stdbool.h>

typedef enum {
    START = 0,
    CODE,
    ADD,
    COMMIT,
    PUSH,
    MAKEPR,
    TRYGETAPPROVE,
    DEFEND,
    STATECOUNT, // DO NOT USE LIKE NAME
    END
} StateName;

typedef struct State;

typedef struct {
    State* pipeline;
    StateName cur_state;
    int step;
    bool is_pr_exists;
} StateMachine;

typedef struct State {
    StateName name;
    StateName (*action)(StateMachine*); // return next state
} State;