#pragma once

#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

typedef uint32_t Bitset;

Bitset bitset = 0u;
int length = 0;

bool check_uppercase(char* word) {
    int length = strlen(word);
    int count = 0;

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
      
        if (check_uppercase(word)) {
            printf("The word '%s' contains more than one uppercase letter.\n", word);
        } else {
            printf("The word '%s' contains only one uppercase letter or none.\n", word);
        }
        word = strtok(NULL, " ");
    }

    return 0;
}