#pragma once

#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

typedef uint32_t Bitset;

// Sibilant consonants:
// sh, ch, zh, th

bool CheckForSibilantConsonants(char c, Bitset* sibilant_consonants) {
    if (isalpha(c)) {
        c = (char)tolower(c);
    }
    if (((c == 's') || (c == 'c') || (c == 't') || (c == 'z')) && (sibilant_consonants == 0)) {
        sibilant_consonants* |= (1u << (c - 'a'));
        return false;
    } else if ((c == 'h') && (sibilant_consonants != 0)) {
        sibilant_consonants* |= (1u << (c - 'a'));
        return true;
    } else {
        sibilant_consonants = 0;
        return false;
    }
}

void PrintSibilantConsonant(const Bitset sibilant_consonants) {
    char symbol = 0;
    for (int i = 0; i < 26; ++i) {
        if (sibilant_consonants & (1u << i)) {
            symbol = (char)((int)'a' + i);
            if (symbol != 'h') {
                printf("%c", (char)symbol);
            }
        }
    }
    printf("%c", 'h');
}

int Task() {
    Bitset sibilant_consonants = 0;
    char input_letter = 0;
    while ((input_letter = (char)getchar()) != EOF) {
        if (CheckForSibilantConsonants(input_letter, &sibilant_consonants)) {
            printf("A word consisting of at least one sibilant was detected: ");
            PrintSibilantConsonant(sibilant_consonants);
            break;
        }
    }
    return 0;
}