#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

typedef uint32_t Bitset;
const Bitset VOICED_CONSONANTS = 48446026;
const Bitset WITHOUT_LETTERS = 0;

bool AreAllConsonantsUnvoiced(const Bitset text) {
    return (text & VOICED_CONSONANTS) == WITHOUT_LETTERS;
}

int Task() {
    Bitset word = 0;
    char c = 0;
    bool the_right_word_exist = false;

    while ((c = (char)getchar()) != EOF) {
        if (c == ' ' || c == '\n') {
            if (AreAllConsonantsUnvoiced(word)) {
                the_right_word_exist = true;
            }
            word = 0;
            continue;
        }
        word = word | 1u << (c - 'a');
    }

    if (the_right_word_exist) {
        printf("yes");
    } else {
        printf("no");
    }

    return 0;
}
