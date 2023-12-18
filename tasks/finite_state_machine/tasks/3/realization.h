#pragma once

#include "shared_header.h"
#include "state.h"

StateMachine* MakeStateMachine() {
    StateMachine* sm = (StateMachine*)malloc(sizeof(StateMachine));
    sm->pipeline = MakeStates();
    sm->cur_state = START;
    sm->current_symbol = ' ';
    sm->count_words = 0;
    sm->step = 0;
    return sm;
}

int Step(StateMachine* sm, char ch) {
    StateName next = sm->pipeline[(int)sm->cur_state].action(sm, ch);
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