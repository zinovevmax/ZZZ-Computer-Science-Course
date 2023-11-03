#pragma once

#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

typedef uint32_t Bitset;

// Sibilant consonants:
// sh, ch, zh, th

Bitset sibilantConsonants = 0;

bool CheckForSibilantConsonants(char c) {
    c = tolower(c);
    if ((c == 's') || (c == 'c') || (c == 'h') || (c == 't') || (c == 'z')) {
        if (sibilantConsonants == 0) {
            if (c != 'h')
                sibilantConsonants |= (1u << (c - 'a'));
            return false;
        }
        else {
            if (c == 'h')
                return true;
        }
    }
    else {
        sibilantConsonants = 0;
        return false;
    }
}

int Task() {
    char input_letter;
    while ((input_letter = (char)getchar()) != EOF)
    {
        bool answer = CheckForSibilantConsonants(input_letter);
        if (answer) {
            printf("A word consisting of at least one sibilant was detected!");
            break;
        }
    }
    return 0;
}