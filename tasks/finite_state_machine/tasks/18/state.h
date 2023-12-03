#pragma once

#include <stdbool.h>
#include <stdlib.h>

#include "shared_header.h"

double CelsiusToFahrenheit(int celsius) {
    return celsius * 9.0 / 5.0 + 32;
}

StateName Start(StateMachine* sm) {
    printf("Finite State Machine has started its execution:\n\n");
    if (sm->ch == '-') {
        sm->num_is_neg = true;
        return VALUEFORMING;
    } else if (sm->ch >= '0' && sm->ch <= '9') {
        sm->num = sm->ch - '0';
        return VALUEFORMING;
    } else {
        return CHARCHECK;
    }
}

StateName CharCheck(StateMachine* sm) {
    if (sm->ch == '-') {
        sm->num_is_neg = true;
        return VALUEFORMING;
    } else if (sm->ch >= '0' && sm->ch <= '9') {
        sm->num = sm->ch - '0';
        return VALUEFORMING;
    } else if (sm->ch == EOF) {
        return END;
    } else {
        return CHARCHECK;
    }
}

StateName ValueForming(StateMachine* sm) {
    if (sm->ch == '*') {
        return TOFAHRENHEIT;
    } else if (sm->ch >= '0' && sm->ch <= '9') {
        sm->num = sm->num * 10 + (sm->ch - '0');
        return VALUEFORMING;
    } else if (sm->ch == EOF) {
        return END;
    } else {
        sm->num_is_neg = false;
        sm->num = 0;
        return CHARCHECK;
    }
}

StateName ToFahrenheit(StateMachine* sm) {
    if (sm->ch == 'C') {
        if (sm->num_is_neg) {
            sm->num *= -1;
        }
        printf("%dC = %gF\n", sm->num, CelsiusToFahrenheit(sm->num));
        return CHARCHECK;
    } else if (sm->ch >= '0' && sm->ch <= '9') {
        sm->num = sm->ch - '0';
        return VALUEFORMING;
    } else if (sm->ch == '-') {
        sm->num_is_neg = true;
        return VALUEFORMING;
    } else if (sm->ch == EOF) {
        return END;
    } else {
        sm->num_is_neg = false;
        sm->num = 0;
        return CHARCHECK;
    }
}

// Add StateNames here

State* MakeStates() {
    State* st = (State*)malloc(sizeof(State) * STATECOUNT);
    int i = -1;
    st[i] = State{(StateName)i++, &Start};
    st[i] = State{(StateName)i++, &CharCheck};
    st[i] = State{(StateName)i++, &ValueForming};
    st[i] = State{(StateName)i++, &ToFahrenheit};
    // Add initializations for states here
    return st;
}

void DeleteStates(State* st) {
    free(st);
}