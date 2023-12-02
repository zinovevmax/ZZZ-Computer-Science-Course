#pragma once

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "shared_header.h"

StateName Start(StateMachine* sm) {
    if (sm->ch >= '0' && sm->ch <= '7') {
        sm->octal_number = sm->ch - '0';
        return VALUEFORMING;
    } else if (sm->ch == EOF) {
        return END;
    } else {
        return NUMCHECK;
    }
}

StateName NumCheck(StateMachine* sm) {
    if (sm->ch >= '0' && sm->ch <= '7') {
        sm->octal_number = sm->ch - '0';
        return VALUEFORMING;
    } else if (sm->ch == EOF) {
        return END;
    } else {
        return NUMCHECK;
    }
}

StateName ValueForming(StateMachine* sm) {
    if (sm->ch == ' ' || sm->ch == '.') {
        return CONVERT;
    } else if (sm->ch >= '0' && sm->ch <= '7') {
        sm->octal_number = sm->octal_number * 10 + (sm->ch - '0');
        return VALUEFORMING;
    } else if (sm->ch == EOF) {
        return END;
    } else {
        return NUMCHECK;
    }
}

StateName ConvertToBinary(StateMachine* sm) {
    int start_number = sm->octal_number;
    sm->reversed_number = 0;
    int division_remainder = 0;
    while (start_number != 0) {
        division_remainder = start_number % 10;
        sm->reversed_number = sm->reversed_number * 10 + division_remainder;
        start_number /= 10;
    }
    int value_power_of_ten = 1;
    printf("Octal number:%d \nBinary form of digits: ", sm->octal_number);
    while (sm->reversed_number >= value_power_of_ten) {
        sm->digit = (sm->reversed_number / value_power_of_ten) % 10;
        int binary_number = 0;
        int power_of_ten = 1;
        while (sm->digit != 0) {
            binary_number += (sm->digit % 2) * power_of_ten;
            power_of_ten *= 10;
            sm->digit /= 2;
        }
        printf("%d ", binary_number);
        value_power_of_ten *= 10;
    }
    printf("\n");
    return NUMCHECK;
}

State* MakeStates() {
    State* st = (State*)malloc(sizeof(State) * STATECOUNT);
    StateName (*actions[STATECOUNT])(StateMachine*) = {&Start, &NumCheck, &ValueForming, &ConvertToBinary};
    for (int i = 0; i < STATECOUNT; ++i) {
        st[i].name = (StateName)i;
        st[i].action = actions[i];
    }
    return st;
}

void DeleteStates(State* st) {
    free(st);
}
