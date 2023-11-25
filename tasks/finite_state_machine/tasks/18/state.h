#pragma once

#include <stdbool.h>
#include <stdlib.h>

#include "shared_header.h"

StateName Start(StateMachine* sm) {
    ++sm->step;
    printf("Finite State Machine has started its execution:\n\n");
    return NUMCHECK;
}

StateName NumCheck(StateMachine* sm) {
    ++sm->step;
    sm->num_is_found = fscanf(sm->file, "%d", &sm->celsius);
    if (sm->num_is_found == 1) {
        return CONVERT;
    }
    return END;
}

StateName Convert(StateMachine* sm) {
    ++sm->step;
    sm->fahrenheit = 9.0 * sm->celsius / 5.0 + 32.0;
    printf("%dC = %gF\n", sm->celsius, sm->fahrenheit);
    return NUMCHECK;
}

// Add StateNames here

State* MakeStates() {
    State* st = (State*)malloc(sizeof(State) * STATECOUNT);
    int i = 0;

    st[i].name = (StateName)i;
    st[i].action = &Start;
    i++;

    st[i].name = (StateName)i;
    st[i].action = &NumCheck;
    i++;

    st[i].name = (StateName)i;
    st[i].action = &Convert;
    i++;

    // Add initializations for states here

    return st;
}

void DeleteStates(State* st) {
    free(st);
}