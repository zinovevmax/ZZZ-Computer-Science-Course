#pragma once

#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

typedef uint32_t Bitset;

const uint32_t RIGHT_VOWELS = 17826048;

bool IsVowel(char letter) {
    return (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'u' || letter == 'y' || letter == 'o');
}

int Task() {
    // write your solution here
    char introduced_char = 0;
    Bitset word = 0;
    int8_t flag = 0;
    while ((introduced_char = (char)getchar()) != EOF) {
        introduced_char = (char)tolower(introduced_char);
        if ('a' <= introduced_char && introduced_char <= 'z') {
            if (IsVowel(introduced_char)) {
                word = word | (1u << (introduced_char - 'a'));
            }
        } else {
            if (RIGHT_VOWELS == (RIGHT_VOWELS | word) && word != 0) {
                flag = 1;
            }
            word = 0;
        }
    }
    if (flag) {
        printf("There are words containing vowels of 2 kinds");
    } else {
        printf("There are no words containing vowels of the 2nd kind");
    }
    return 0;
}