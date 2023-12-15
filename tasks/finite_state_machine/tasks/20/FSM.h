#pragma once

#include "fsm_realization.h"

int Task() {
    /*
    Regular for search miles: (-?\d*)mi
    Another for floating numbers: (-?\d+\.?\d*)mi

    TESTS:
    I have an idea to go for a 20mi ride. -> 20

    */
    FILE* file = fopen("../tasks/finite_state_machine/tasks/20/input_file.txt", "r");
    StateMachine* sm = MakeStateMachine();
    printf("Finite State Machine has started its execution:\n\n");
    
    int result = 0;
    while (true) {
        result = Step(sm, (char)fgetc(file));
        if (result) {
            printf("\nFSM has completed its execution\n");
            break;
        }
    }

    DeleteStateMachine(sm);
    fclose(file);
    return 0;
}