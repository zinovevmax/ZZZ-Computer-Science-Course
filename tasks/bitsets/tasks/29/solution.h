#pragma once

#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

typedef uint32_t Bitset;

const Bitset BITSETS = 0u;

bool CheckUppercase(char* word) {
    int length = (int)strlen(word);
    int count = 0;
    Bitset bitset = BITSETS;

    for (int i = 0; i < length; i++) {
        if (word[i] >= 'A' && word[i] <= 'Z') {
            int index = word[i] - 'A';
            bitset |= (1u << (index % CHAR_BIT));
        }
    }

    for (int i = 0; i < 2; i++) {
        while (bitset) {
            count += bitset & 1;
            bitset >>= 1;
        }
    }

    return count > 1;
}

int Task() {

    char sentence[] = "Mama mYLa ramu";
    char* word = strtok(sentence, " ");
    while (word != NULL) {
        if (CheckUppercase(word)) {
            printf("The word '%s' contains more than one uppercase letter.\n", word);
        } else {
            printf("The word '%s' contains only one uppercase letter or none.\n", word);
        }
        word = strtok(NULL, " ");
    }

    return 0;
}