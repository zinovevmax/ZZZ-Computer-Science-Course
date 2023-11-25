#pragma once

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "shared_header.h"
#include "state.h"

StateMachine* MakeStateMachine(FILE* filename) {
    StateMachine* sm = (StateMachine*)malloc(sizeof(StateMachine));
    sm->pipeline = MakeStates();
    sm->cur_state = START;
    sm->step = 0;
    sm->file = filename;
    sm->celsius = 0;
    sm->num_is_found = 0;
    sm->fahrenheit = 0;
    return sm;
}

int Step(StateMachine* sm) {
    StateName next = sm->pipeline[(int)sm->cur_state].action(sm);
    if (next == END) {
        return 1;
    }
    sm->cur_state = next;
    return 0;
}

void DeleteStateMachine(StateMachine* sm) {
    DeleteStates(sm->pipeline);
    free(sm);
}