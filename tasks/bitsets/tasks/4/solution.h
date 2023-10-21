#pragma once

#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

typedef uint32_t Bitset;
const int32_t A_INDEX = 'a' - 'a';
const int32_t E_INDEX = 'e' - 'a';
const int32_t I_INDEX = 'i' - 'a';
const int32_t O_INDEX = 'o' - 'a';
const int32_t Y_INDEX = 'y' - 'a';

bool CharIsConsonant(int32_t index) {
    return (index != A_INDEX && index != E_INDEX && index != I_INDEX && index != O_INDEX && index != Y_INDEX);
}

int Task() {
    char inputed_char = 0;
    bool word_with_repeated_consonant_is_found = false;
    int32_t index = 0;
    Bitset previous_word_letters_set = 0;
    Bitset word_letters_set = 0;
    while ((inputed_char = (char)getchar()) != EOF) {
        if (isalpha(inputed_char)) {
            inputed_char = (char)tolower(inputed_char);
            index = inputed_char - 'a';
            word_letters_set |= (1 << index);
            if (previous_word_letters_set == word_letters_set && CharIsConsonant(index)) {
                word_with_repeated_consonant_is_found = true;
                break;
            } else {
                previous_word_letters_set = word_letters_set;
            }
        } else {
            word_letters_set = 0;
            previous_word_letters_set = 0;
        }
    }
    if (word_with_repeated_consonant_is_found) {
        printf("A word with at least one repeating consonant was found\n");
    } else {
        printf("A word with at least one repeating consonant was not found\n");
    }
    return 0;
}