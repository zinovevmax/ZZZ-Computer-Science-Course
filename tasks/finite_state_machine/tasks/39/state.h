#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#include "shared_header.h"

bool IsHexDigit(char c) {
    return (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f') || (c >= '0' && c <= '9');
}

StateName Find(StateMachine* sm) {
    if (sm->current_char == '0') {
        return PREFIX;
    } else {
        return FIND;
    }
}

StateName Prefix(StateMachine* sm) {
    if (sm->current_char == 'x' || sm->current_char == 'X') {
        return CHECKSIGN;
    } else {
        return Find(sm);
    }
}

StateName CheckSign(StateMachine* sm) {
    // Нам нужны только отрицательные числа, поэтому нужно проверить верхний разряд в довоичном представлении
    if (IsHexDigit(sm->current_char) && (sm->current_char >= '8')) {
        ++sm->length_count;
        return CHECKCORRECT;
    } else {
        return Find(sm);
    }
}

StateName CheckCorrect(StateMachine* sm) {
    // Если очередная цифра подходит, увеличиваем счётчик длины
    if (sm->length_count < HEX_LENGTH && IsHexDigit(sm->current_char)) {
        ++sm->length_count;
        return CHECKCORRECT;
    }

    // Иначе если это было HEX числом, увеличиваем счётчик подошедших чисел.
    if (sm->length_count == HEX_LENGTH) {
        ++sm->numbers_count;
        sm->length_count = 0;
        return FIND;
    }

    // Иначе просто обнуляем счётчик длины проверяемого слова и снова ищем новое число
    sm->length_count = 0;
    if (sm->last_char == '0') {
        return Prefix(sm);
    }
    return Find(sm);
}

State* MakeStates() {
    State* st = (State*)malloc(sizeof(State) * STATECOUNT);

    StateName (*actions[STATECOUNT])(StateMachine*) = {&Find, &Prefix, &CheckSign, &CheckCorrect};
    for (size_t i = 0; i < STATECOUNT; ++i) {
        st[i].name = (StateName)i;
        st[i].action = actions[i];
    }
    return st;
}

void DeleteStates(State* pipeline) {
    free(pipeline);
}