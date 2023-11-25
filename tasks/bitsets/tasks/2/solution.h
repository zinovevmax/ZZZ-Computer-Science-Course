#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

typedef uint32_t Bitset;
const uint32_t CONSONANTS = 66043630u;  //number of Bitset consonants

// Getting Bitset of consonants 
// Bitset ConsonantsAlphabet() {
//     char text[] = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x',
//     'y', 'z'}; uint32_t Set = 0; for (int i = 0; i < strlen(text); ++i) { Set = Set | (1u << (text[i] - 'a')); return
//     Set
//     }
// }

bool CheckIfConsonant(char sign) {
    if (CONSONANTS == (CONSONANTS | (1u << (sign - 'a')))) {
        return 1;
    }
    return 0;
}

bool CheckIfBeenBefore(char sign, Bitset consonants_before) {
    if (consonants_before < (consonants_before ^ (1u << (sign - 'a')))) {
        return 1;
    }
    return 0;
}

int Task() {
    Bitset consonants_before = 0;
    bool repeated_consonant = 0;
    char sign = 0;
    uint32_t space_counter = 0;
    while ((sign = (char)getchar()) != '0') {
        if ((sign == ' ') || (sign == '\n')) {
            space_counter++;
            if ((repeated_consonant == 0) && (space_counter == 0)) {
                printf("yes");
                return 1;
            }
            consonants_before = 0;
            repeated_consonant = 0;
            continue;
        }
        space_counter = 0;
        if (CheckIfConsonant(sign)) {
            if (CheckIfBeenBefore(sign, consonants_before)) {
                consonants_before = (consonants_before ^ (1u << (sign - 'a')));
            } else {
                repeated_consonant = 1;
            }
        }
    }
    if (repeated_consonant == 0) {
        printf("there is at least one word with non-repeating consonants");
        return 1;
    }
    printf("no word with non-repeating consonants");
    return 0;
}