#pragma once

#include <stdbool.h>
#include <stdlib.h>

#include "shared_header.h"

double MilesToKilometrs(int kilometers) {
    return kilometers * 1.609;
}

StateName NumSearch(StateMachine* sm) {
    if (sm->ch >= '0' && sm->ch <= '9') {
        sm->num = sm->ch - '0';
        return VALUEFORMING;
    } else if (sm->ch == EOF) {
        return END;
    } else {
        return NUMSEARCH;
    }
}

StateName ValueForming(StateMachine* sm) {
    if (sm->ch == 'm') {
        return CONVERSIONTOKILOMETRS;
    } else if (sm->ch >= '0' && sm->ch <= '9') {
        sm->num = sm->num * 10 + (sm->ch - '0');
        return VALUEFORMING;
    } else if (sm->ch == EOF) {
        return END;
    } else {
        sm->num = 0;
        return NUMSEARCH;
    }
}

StateName ConversionToKilometrs(StateMachine* sm) {
    if (sm->ch == 'i') {
        printf("%dmi = %gkm\n", sm->num, MilesToKilometrs(sm->num));
        return NUMSEARCH;
    } else if (sm->ch >= '0' && sm->ch <= '9') {
        sm->num = sm->ch - '0';
        return VALUEFORMING;
    } else if (sm->ch == EOF) {
        return END;
    } else {
        sm->num = 0;
        return NUMSEARCH;
    }
}


State* MakeStates() {
    State* st = (State*)malloc(sizeof(State) * STATECOUNT);
    StateName (*actions[STATECOUNT])(StateMachine*) = {&NumSearch, &ValueForming, &ConversionToKilometrs};
    for (int i = 0; i < STATECOUNT; ++i) {
        st[i].name = (StateName)i;
        st[i].action = actions[i];
    }
    return st;
}

void DeleteStates(State* st) {
    free(st);
}