#pragma once

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "shared_header.h"

StateName NumCheck(StateMachine* sm) {
    if (fscanf(sm->file, "%d", &sm->octal_number) == 1) {
        return REVERSE;
    }
    return END;
}

StateName Reverse(StateMachine* sm) {
    int start_number = sm->octal_number;
    sm->reversed_number = 0;
    int division_remainder = 0;
    while (start_number != 0) {
        division_remainder = start_number % 10;
        sm->reversed_number = sm->reversed_number * 10 + division_remainder;
        start_number /= 10;
    }
    return CONVERT;
}

StateName Convert(StateMachine* sm) {
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
    int i = 0;

    st[i].name = (StateName)i;
    st[i].action = &NumCheck;
    i++;

    st[i].name = (StateName)i;
    st[i].action = &Reverse;
    i++;

    st[i].name = (StateName)i;
    st[i].action = &Convert;
    i++;

    return st;
}

void DeleteStates(State* st) {
    free(st);
}