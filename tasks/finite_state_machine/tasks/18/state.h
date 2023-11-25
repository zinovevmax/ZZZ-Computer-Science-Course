#pragma once

#include <math.h>
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
        if (sm->celsius % 5 == 0) {
            sm->is_multiple_of_five = true;
        } else {
            sm->is_multiple_of_five = false;
        }
        return CONVERT;
    }
    return END;
}

StateName Convert(StateMachine* sm) {
    ++sm->step;
    sm->fahrenheit = 9.0 * sm->celsius / 5.0 + 32.0;
    if (sm->is_multiple_of_five) {
        printf("%dC = %.0fF\n", sm->celsius, round(sm->fahrenheit));
    } else {
        printf("%dC = %.1fF\n", sm->celsius, round(sm->fahrenheit * 10) / 10);
    }
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