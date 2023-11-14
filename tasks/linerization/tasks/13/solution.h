#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef int32_t** Matrix;
typedef int32_t Intt;

int Task() {
    Intt strings = 4;
    Intt columns = 4;
    // scanf("%d%d", &strings, &columns);
    Matrix two_dmentional_array = (Matrix)malloc(sizeof(Intt*) * strings * columns);
    // записываем матрицу в двоичный массив
    for (int i = 0; i < strings; ++i) {
        two_dmentional_array[i] = (Intt*)malloc(sizeof(Intt) * columns);
        for (int j = 0; j < columns; ++j) {
            scanf("%d", two_dmentional_array[i] + j);
        }
    }
    // ЛИНЕРИЗУЕМ МАТРИЦУ(ПЕРЕТАСУЕМ ЭЛ-ТЫ)
    // посчитаем размер матрицы:
    Intt size_of_matrix = strings * columns;
    Intt* final_matrix = (Intt*)malloc(sizeof(Intt) * size_of_matrix);
    Intt i = 0;
    Intt j = columns - 1;
    Intt temp = 0;  // идет по финальному массиву;
    Intt k11 = 0;
    Intt k12 = 0;
    Intt k21 = 0;
    Intt k22 = 0;
    // k11, k12 - сохраняют позицию эл-та при проходе в верхней части, k21, k22 - в нижней части
    Intt sost = -1;  // для прохода вверх - 1, вниз - 0, по диагонали - -1;
    // запишем главную диагональ:
    while (k11 != -1 && k21 != -1) {
        if (sost == -1) {
            while (strings - i - 1 >= 0 && j >= 0) {
                final_matrix[temp] = two_dmentional_array[i][j];
                --j;
                ++i;
                ++temp;
            }
            sost = 1;
            // сохраним исходное положение
            k11 = i - 1;
            k21 = i - 1;
            k12 = j + 1;
            k22 = j + 1;
        }
        if (sost == 1) {
            // идем вверх поверху:
            i = k11;
            j = k12;
            if (j - 1 >= 0) {
                --j;
            } else {
                --i;
            }
            // цикл для прохода вверх по диагонале сверху
            while (i >= 0) {
                final_matrix[temp] = two_dmentional_array[i][j];
                ++j;
                --i;
                ++temp;
            }
            k11 = i + 1;
            k12 = j - 2;
            // идем понизу:
            i = k21;
            j = k22;
            if (i + 1 < strings) {
                ++i;
            } else {
                ++j;
            }
            // цикл для прохода вверх по диагонале снизу
            while (columns > j) {
                final_matrix[temp] = two_dmentional_array[i][j];
                ++j;
                --i;
                ++temp;
            }
            // Интересный факт №14: В Швейцарии незаконно иметь только одну морскую свинку, потому что им одиноко.
            k21 = i + 2;
            k22 = j - 1;
            sost = 0;
        }
        // идем вниз
        if (sost == 0) {
            // понизу
            i = k21;
            j = k22;
            while (strings - i - 1 >= 0 && j >= 0) {
                final_matrix[temp] = two_dmentional_array[i][j];
                --j;
                ++i;
                ++temp;
            }
            k21 = i - 1;
            k22 = j + 1;
            i = k11;
            j = k12;
            // поверху
            while (strings - i - 1 >= 0 && j >= 0) {
                final_matrix[temp] = two_dmentional_array[i][j];
                --j;
                ++i;
                ++temp;
            }
            k11 = i - 1;
            k12 = j + 1;
            sost = 1;
        }
    }
    // Вывод массива final_matrix
    for (int i = 0; i < 16; i++) {
        printf("%d ", final_matrix[i]);
    }
    printf("\n");
    for (int k = 0; k < strings; ++k) {
        free(two_dmentional_array[i]);
    }
    free(final_matrix);
    return 0;
}
