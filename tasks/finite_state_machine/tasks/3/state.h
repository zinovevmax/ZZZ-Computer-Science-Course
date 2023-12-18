#pragma once

#include <stdio.h>

#include "shared_header.h"

// Функция, которую выполнит состояние START
StateName Start(StateMachine* sm, char ch) {
    ++sm->step;
    if (ch == '1') {
    }
    printf("Starting...\n");
    return CHECK_SYMBOL_FIRST;
}

StateName CheckSymbolFirst(StateMachine* sm, char ch) {
    ++sm->step;
    if (ch == '{') {
        return WORDS_IN_COMMENT;
    }
    return CHECK_SYMBOL_FIRST;
}

StateName WordsInComment(StateMachine* sm, char ch) {
    ++sm->step;
    if (ch == ' ') {
        return INCREMENT;
    } else if (ch == '}') {
        return END;
    }
    return WORDS_IN_COMMENT;
}

StateName Increment(StateMachine* sm, char ch) {
    ++sm->step;
    ++sm->count_words;
    if (ch == '1') {
    }
    return WORDS_IN_COMMENT;
}

State* MakeStates() {
    State* st = (State*)malloc(sizeof(State) * (int)STATECOUNT);
    int i = -1;
    // Read: https://en.cppreference.com/w/c/language/struct_initialization
    st[i] = State{(StateName)i++, &Start};  // Списки инициализации для структур.
    st[i] = State{(StateName)i++, &CheckSymbolFirst};
    st[i] = State{(StateName)i++, &WordsInComment};
    st[i] = State{(StateName)i++, &Increment};
    return st;
}

void DeleteStates(State* st) {
    free(st);
}