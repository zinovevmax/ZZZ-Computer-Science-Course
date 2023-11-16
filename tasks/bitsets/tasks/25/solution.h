#pragma once

#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

typedef uint32_t Bitset;

// Sibilant consonants:
// sh, ch, zh, th

Bitset sibilant_consonants = 0;

bool CheckForSibilantConsonants(char c) {
    
    if (isalpha(c)) {
        c = tolower(c);
    }
    if (((c == 's') || (c == 'c') || (c == 't') || (c == 'z')) && (sibilant_consonants == 0)) {
        sibilant_consonants |= (1u << (c - 'a'));
        return false;
    } else if ((c == 'h') && (sibilant_consonants != 0)) {
        sibilant_consonants |= (1u << (c - 'a'));
        return true;
    } else {
        sibilant_consonants = 0;
        return false;
    }
}

void PrintSibilantConsonant() {
    char symbol = 0;
    for (size_t i = 0; i < 26; ++i) {
        if (sibilant_consonants & (1u << i)) {
            symbol = 'a' + i;
            if (symbol != 'h') {
                printf("%s", (char)symbol);
            }
        }
    }
    printf("%s", 'h');
}

int Task() {
    char input_letter = 0;
    while ((input_letter = (char)getchar()) != EOF) {
        if (CheckForSibilantConsonants(input_letter)) {
            printf("A word consisting of at least one sibilant was detected: ");
            PrintSibilantConsonant();
            break;
        }
    }
    return 0;
}