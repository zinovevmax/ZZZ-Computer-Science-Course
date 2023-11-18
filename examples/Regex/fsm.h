#pragma once

#include "shared_header.h"

#include "state.h"


StateMachine* MakeStateMachine() {
    StateMachine* sm = (StateMachine*)malloc(sizeof(StateMachine));
    sm->pipeline = MakeStates();
    sm->cur_state = START;
    sm->step = 0;
    sm->is_pr_exists = false;
    return sm;
}

int NextStep(StateMachine* sm, char) {
    StateName next;
    next = sm->pipeline[(int)sm->cur_state].action(sm);
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