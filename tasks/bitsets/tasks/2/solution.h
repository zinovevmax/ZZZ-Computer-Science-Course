
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

typedef uint32_t Bitset;
const uint32_t CONSONANTS = 66043630u;  // number of Bitset consonants

// Getting Bitset of consonants
// Bitset ConsonantsAlphabet() {
//     char text[] = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x',
//     'y', 'z'}; uint32_t Set = 0; for (int i = 0; i < strlen(text); ++i) { Set = Set | (1u << (text[i] - 'a')); return
//     Set
//     }
// }

bool CheckIfConsonant(char sign) {
    if (CONSONANTS == (CONSONANTS | (1u << (sign - 'a')))) {
        return true;
    }
    return false;
}

bool CheckIfBeenBefore(char sign, Bitset consonants_before) {
    if (consonants_before < (consonants_before ^ (1u << (sign - 'a')))) {
        return false;
    }
    return true;
}

int main() {
    // write your solution here
    Bitset consonants_before = 0;
    bool repeated_consonant = false;
    char sign = 0;
    uint32_t space_counter = 0;
    while ((sign = (char)getchar()) != '\n') {
        if ((sign == ' ') || (sign == '\n')) {
            if ((repeated_consonant == false) && (space_counter == 0)) {
                printf("there is at least one word with non-repeating consonants");
                return 0;
            }
            space_counter++;
            consonants_before = 0;
            repeated_consonant = false;
            continue;
        }
        space_counter = 0;
        if (CheckIfConsonant(sign)) {
            if (CheckIfBeenBefore(sign, consonants_before) == false) {
                consonants_before = (consonants_before ^ (1u << (sign - 'a')));
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