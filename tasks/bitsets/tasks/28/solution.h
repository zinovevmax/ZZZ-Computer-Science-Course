#pragma once

#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

typedef uint32_t Bitset;

// Проверка на присутствие буквы в слове
bool VowelWord(Bitset num, Bitset a, Bitset b) {
    if ((num & a) > 0 && (num & b) == 0) {
        return true;
    }
    return false;
}

int Task() {
    // Объявление переменной и ввод
    char c = ' ';
    c = getchar();
    Bitset vowels = (1 << ('e' - 'a')) + (1 << ('y' - 'a')) + (1 << ('u' - 'a')) + (1 << ('i' - 'a')) +
                    (1 << ('o' - 'a')) + (1 << ('a' - 'a')) + (1 << ('j' - 'a'));
    Bitset consonants = ~vowels;
    Bitset set = 0;
    // Счётчик слов
    uint16_t counter = 0;
    // Цикл до ко конца строки
    while (c != '\n') {
        c = tolower(c);
        // заполнение bitset
        if (isalpha(c)) {
            set = set | (1 << (c - 'a'));
        }
        // Проверка слова
        else if (c == ' ') {
            if (VowelWord(set, vowels, consonants)) {
                counter++;
            }
            set = 0;
        }
        c = getchar();
    }
    if (VowelWord(set, vowels, consonants)) {
        counter++;
    }
    if (counter > 0) {
        printf("Да, %d подходит", counter);
    } else {
        printf("Нет слов, состоящих только из гласных букв");
    }
    return 0;
}