#pragma once

#include <stdbool.h>

#include "stdlib.h"

typedef enum {
    FINDFIRSTSYMSTARTCOMM = 0,
    FINDSECONDSYMSTARTCOMM,
    COMMENTDETECTED,
    FINDFIRSTSYMFINISHCOM,
    STATECOUNT,
    END
} StateName;

typedef struct State State;

typedef struct {
    State* pipeline;
    StateName cur_state;
    int count_words;
    char lastsym;
} StateMachine;

typedef struct State {
    StateName name;
    StateName (*action)(StateMachine*, char ch);
} State;