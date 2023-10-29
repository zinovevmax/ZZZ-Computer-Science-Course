#pragma once

#include <ctype.h>
#include <stdint.h>
#include <stdio.h>

typedef uint32_t Bitset;
const Bitset Set = 0;
const Bitset WITHOUT_VOWELS = 4277124846;

// получаем WITHOUT_VOWELS:
// char vowels[] = {'a', 'e', 'i', 'o', 'y', 'u'};
// Bitset only_vowels = 0; // empty bitset
// for (int i = 0; i < sizeof(vowels); ++i) {
//     only_vowels |= (1u << (vowels[i] - 'a'));
// }
// Bitset WITHOUT_VOWELS = UINT32_MAX ^ only_vovels;
// printf("%lld", WITHOUT_VOWELS);

Bitset popcount(Bitset a) {
    Bitset count = 0;
    while (a) {
        count += a & 1;  // проверяем последний бит числа
        a >>= 1;         // сдвигаем число вправо на 1 бит
    }
    return count;
}
// popcount возвращает количество единиц в двоичной записи числа
int Task() {
    int flag = 0;  // в дальнейшем флаг используется для определения положительного результата
    char ch;
    Bitset set = Set;  // создаем пустое множество
    // вводим символы до конца ввода
    while ((ch = getchar()) != EOF) {
        if (isalpha(ch)) {
            set = set | (1 << (ch - 'a'));
        } else {
            if (popcount((set | WITHOUT_VOWELS) ^ WITHOUT_VOWELS) == 1) {
                flag = 1;  // означает что нашли такое слово
            } else {
                set = Set;  // иначе сбрасываем множество до 0, тк переходим к новому слову
            }
        }
    }
    // если у нас ввод закончился на конце слова,
    // проверяем это слово на наличие 1 гласной
    if (popcount((set | WITHOUT_VOWELS) ^ WITHOUT_VOWELS) == 1) {
        flag = 1;
    }
    if (flag) {
        printf("YES");
    } else {
        printf("NO");
    }
    return 0;
}
