#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

typedef uint32_t Bitset;

// Getting Bitset of consonants
Bitset ConsonantsAlphabet() {
    char text[] = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z'};
    uint32_t Set = 0;
    for (int i = 0; i < strlen(text); ++i) {
        Set = Set | (1u << (text[i] - 'a'));
    }
    return Set
}

bool IsConsonant(char symbol) {
    return (CONSONANTS == (CONSONANTS | (1u << (symbol - 'a'))));
}

bool IsBeenBefore(char symbol, Bitset consonants_before) {
    return (consonants_before >= (consonants_before ^ (1u << (symbol - 'a'))));
}

int Task() {
    bool repeated_consonant = false;
    uint32_t space_counter = 0;
    Bitset consonants_before = 0;
    Bitset CONSONANTS = 0u;
    char symbol = 0;
    CONSONANTS = ConsonantsAlphabet();
    while ((symbol = (char)getchar()) != EOF) {
        if ((symbol == ' ') || (symbol == '\n')) {
            if ((repeated_consonant == false) && (space_counter == 0)) {
                printf("there is at least one word with non-repeating consonants");
                return 0;
            }
            ++space_counter;
            consonants_before = 0;
            repeated_consonant = false;
            continue;
        }
        space_counter = 0;
        if (IsConsonant(symbol)) {
            if (IsBeenBefore(symbol, consonants_before) == false) {
                consonants_before = (consonants_before ^ (1u << (symbol - 'a')));
            } else {
                repeated_consonant = true;
            }
        }
    }
    if (repeated_consonant == 0) {
        printf("there is at least one word with non-repeating consonants");
        return 0;
    }
    printf("no word with non-repeating consonants");
    return 0;
}