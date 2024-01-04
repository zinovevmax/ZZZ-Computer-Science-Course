#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

typedef uint32_t Bitset;

const Bitset VOWELS = 17842449;

int Task() {
    char c = 0;
    Bitset letters_set_1 = 0;
    Bitset letters_set_2 = 0;
    bool answer = false;
    while ((c = (char)getchar()) != EOF) {
        letters_set_2 = letters_set_2 | 1u << (c - 'a');
        if (c == ' ' || c == '\n') {
            if ((letters_set_2 & VOWELS) == (letters_set_1 & VOWELS)) {
                answer = true;
            }
            letters_set_1 = letters_set_2;
            letters_set_2 = 0;
        }
    }
    if (answer == true) {
        printf("YES");
    } else {
        printf("NO");
    }
    return 0;
}
