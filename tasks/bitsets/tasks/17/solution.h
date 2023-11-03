#pragma once

#include <ctype.h>
#include <stdint.h>
#include <stdio.h>

typedef uint32_t Bitset;

int8_t IsVowal(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y') {
        return 1;
    } else {
        return 0;
    }
}

int Task() {
    // write your solution here
    char symbol = 0;
    Bitset vowals_of_new_word = 0u;
    Bitset vowals_of_last_word = 0u;
    int8_t is_success = 0;
    int8_t is_letter = 0;
    while (scanf("%c", &symbol) != EOF) {
        symbol = char(tolower(symbol));
        if ('a' <= symbol && symbol <= 'z') {
            if (IsVowal(symbol)) {
                vowals_of_new_word = vowals_of_new_word | (1u << (symbol - 'a'));
            }
            is_letter = 1;
        } else {
            if (vowals_of_new_word & vowals_of_last_word == vowals_of_new_word && is_letter) {
                printf("Есть два соседних слова с пересекающимся набором гласных.\n");
                is_success = 1;
                break;
            }
            vowals_of_last_word = vowals_of_new_word;
            vowals_of_new_word = 0u;
            is_letter = 0;
        }
    }
    if (!is_success) {
        printf("Нет двух соседних слов с пересекающимся набором гласных\n");
    }
    return 0;
}