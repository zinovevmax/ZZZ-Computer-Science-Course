#pragma once
#include <stdio.h>
#include <stdlib.h>

#include "shared_header.h"

StateName Start(StateMachine* sm, char c) {
    printf("Program has started its execution\n\n");
    sm->last_symbol = c;
    if (c == EOF) {
        printf("\n\n");
        return END;
    } else if (c != '\n') {
        printf("%c", c);
    }
    return SYMBOLCHECK;
}

StateName SymbolCheck(StateMachine* sm, char c) {
    if (c == '\n' && sm->last_symbol != '\n') {
        sm->last_symbol = c;
        printf(" ");
        return SYMBOLCHECK;
    } else if (c == '\n' && sm->last_symbol == '\n') {
        return SYMBOLCHECK;
    } else if (c == EOF) {
        printf("\n\n");
        return END;
    } else {
        printf("%c", c);
        sm->last_symbol = c;
        return SYMBOLCHECK;
    }
}

State* MakeStates() {
    State* st = (State*)malloc(sizeof(State) * STATECOUNT);
    int i = 0;
    st[i].name = (StateName)i;
    st[i].action = &Start;
    ++i;
    st[i].name = (StateName)i;
    st[i].action = &SymbolCheck;
    return st;
}

void DeleteStates(State* st) {
    free(st);
}