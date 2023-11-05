#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef int32_t** Matrix;
typedef int32_t* Row;

typedef struct {
    size_t start;
    size_t end;
} Slice;

#define isLess(x, y) ((y >= x) ? 1 : 0)

void Swap(size_t* n, size_t* m) {
    size_t t = *n;
    *n = *m;
    *m = t;
}

// Заполняет массив числами по спирали, начиная с левого нижнего угла и двигаясь по часовой стрелке
void Fill(Matrix matrix, size_t n, size_t m) {
    int32_t element = 1;

    Slice y_axis = {n - 1, 0};
    Slice x_axis = {m - 1, 0};

    int32_t is_horizontal = 0;
    int32_t step = 0;

    while (element <= (int32_t)(n * m)) {
        if (is_horizontal) {
            step = 2 * isLess(x_axis.start, x_axis.end) - 1;
            for (size_t j = x_axis.start; j != x_axis.end + step; j += step) {
                if (matrix[y_axis.end][j] != 0) {
                    break;
                }
                matrix[y_axis.end][j] = element++;
            }

            Swap(&y_axis.start, &y_axis.end);
            y_axis.start += 2 * isLess(y_axis.start, y_axis.end) - 1;
        } else {
            step = 2 * isLess(y_axis.start, y_axis.end) - 1;
            for (size_t i = y_axis.start; i != y_axis.end + step; i += step) {
                if (matrix[i][x_axis.end] != 0) {
                    break;
                }
                matrix[i][x_axis.end] = element++;
            }

            Swap(&x_axis.start, &x_axis.end);
            x_axis.start += 2 * isLess(x_axis.start, x_axis.end) - 1;
        }

        is_horizontal = !is_horizontal;
    }
}

void Linerization(Matrix matrix, Row lin_matrix, size_t n, size_t m) {
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            lin_matrix[i * m + j] = matrix[i][j];
        }
    }
}

void PrintMatrix(Matrix matrix, size_t n, size_t m) {
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void PrintRow(Row row, size_t n) {
    for (size_t i = 0; i < n; ++i) {
        printf("%d ", row[i]);
    }
    printf("\n");
}

const size_t N = 6;
const size_t M = 9;

int Task() {
    size_t n = N;
    size_t m = M;
    // scanf("%lu%lu", &n, &m);

    // Инициализируем матрицу
    Row lin_matrix = (Row)calloc(n * m, sizeof(Row));
    Matrix matrix = (Matrix)calloc(n, sizeof(Row));
    for (size_t i = 0; i < n; ++i) {
        matrix[i] = (Row)calloc(m, sizeof(Row));
    }

    // Решаем задачу
    Fill(matrix, n, m);
    Linerization(matrix, lin_matrix, n, m);

    // Выводим результат
    PrintMatrix(matrix, n, m);
    printf("\n");
    PrintRow(lin_matrix, n * m);

    // Освобождаем память
    for (size_t i = 0; i < n; ++i) {
        free(matrix[i]);
    }
    free(matrix);
    free(lin_matrix);

    return 0;
}
