#pragma once

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum { NUMSEARCH = 0, VALUEFORMING, CONVERSIONTOKILOMETRS, STATECOUNT, END } StateName;

typedef struct State State;

typedef struct {
    State* pipeline;
    StateName cur_state;
    char ch;
    int num;
} StateMachine;

typedef struct State {
    StateName name;
    StateName (*action)(StateMachine*);
} State;
