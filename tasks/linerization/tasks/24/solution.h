#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef int32_t** Matrix;
typedef int32_t* Row;

typedef struct {
    size_t s;
    size_t e;
} Slice;

void Swap(size_t* n, size_t* m) {
    size_t t = *n;
    *n = *m;
    *m = t;
}

void Fill(Matrix matrix, size_t n, size_t m) {
    int32_t element = 0;
    Slice ver = {n - 1, 0};
    Slice hor = {m - 1, 0};
    int32_t is_hor = 0;
    int32_t sign = 0;

    int32_t run = 1;
    while (run) {
        run = !(ver.s == ver.e && hor.s == hor.e);
        if (is_hor) {
            sign = (hor.e > hor.s) ? 1 : -1;
            for (size_t j = hor.s; j != hor.e + sign; j += sign) {
                matrix[ver.e][j] = ++element;
            }
            is_hor = 0;
            Swap(&ver.s, &ver.e);
            ver.s += (ver.e >= ver.s) ? 1 : -1;
        } else {
            sign = (ver.e >= ver.s) ? 1 : -1;
            for (size_t i = ver.s; i != ver.e + sign; i += sign) {
                matrix[i][hor.e] = ++element;
            }
            is_hor = 1;
            Swap(&hor.s, &hor.e);
            hor.s += (hor.e > hor.s) ? 1 : -1;
        }
    }
}

void Linerization(Matrix matrix, Row lin_matrix, size_t n, size_t m) {
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            lin_matrix[i * m + j] = matrix[i][j];
        }
    }
}

const size_t N = 6;
const size_t M = 9;

int Task() {
    size_t n = N;
    size_t m = M;
    // scanf("%lu%lu", &n, &m);
    Matrix matrix = (Matrix)calloc(n, sizeof(Row));
    for (size_t i = 0; i < n; ++i) {
        matrix[i] = (Row)calloc(m, sizeof(Row));
    }

    Fill(matrix, n, m);
    Row lin_matrix = (Row)calloc(n * m, sizeof(Row));
    Linerization(matrix, lin_matrix, n, m);

    // Освобождаем память
    for (size_t i = 0; i < n; ++i) {
        free(matrix[i]);
    }
    free(matrix);
    free(lin_matrix);

    return 0;
}
