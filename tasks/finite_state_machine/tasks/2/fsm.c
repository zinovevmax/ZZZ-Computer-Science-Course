#pragma once

#include "shared_header.c"
#include "state.c"

StateMachine* MakeStateMachine() {
    StateMachine* sm = (StateMachine*)malloc(sizeof(StateMachine));
    sm->pipeline = MakeStates();
    sm->cur_state = FINDFIRSTSYMBOLCOMMENTS1;
    sm->step = 0;
    sm->count = 0;
    sm->lastsym = ' ';
    return sm;
}

int Step(StateMachine* sm, char ch) {
    StateName next;
    next = sm->pipeline[(int)sm->cur_state].action(sm, ch);
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