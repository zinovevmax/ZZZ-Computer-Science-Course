#pragma once

#include <stdint.h>
#include <stdlib.h>

typedef enum {
    FIND,  // Состояние поиска знака '0', с которого бы начиналось HEX число
    PREFIX,  // Если после 0 идёт x, то машина встретила правильное начало HEX числа
    CHECKSIGN,  // Т.к. требуется посчитать только отрицательные числа, нужно проверить знаковый бит
    CHECKCORRECT,  // Состояние проверки правильности числа
                   // Новые состояние писать тут
    STATECOUNT,    // Количество состояний
} StateName;

typedef struct State State;

typedef struct {
    State* pipeline;
    StateName cur_state;
    size_t length_count;
    size_t numbers_count;
    char current_char;
} StateMachine;

typedef struct State {
    StateName name;
    StateName (*action)(StateMachine*);
} State;

// Зайцев бы сказал, что я программирую на 16-битных кухонных часах,
// но маленькое число для простоты отладки
const int64_t HEX_LENGTH = 4;