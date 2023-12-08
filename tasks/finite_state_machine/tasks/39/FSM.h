#pragma once

#include <stdio.h>

#include "fsm.h"

// решение в регвырах:
// 0[xX][8-9A-Fa-f][0-9A-Fa-f]{3} последнее число в {} это просто HEX_LENGTH - 1 (see shared_header.h)

int Task() {
    StateMachine* sm = CreateStateMachine();
    FILE* fp = fopen("../tasks/finite_state_machine/tasks/39/test.txt", "r");
    char c;

    while ((c = fgetc(fp)) != EOF) {
        Step(sm, c);
    }
    Step(sm, ' ');

    printf("%lu negative hex numbers was finded!\n", sm->numbers_count);

    DeleteStateMachine(sm);
    fclose(fp);
    return 0;
}