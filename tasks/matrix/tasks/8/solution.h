#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef int32_t **Matrix;
typedef int32_t *Row;

#define Abs(x) ((x < 0) ? -x : x)
#define Max(x, y) ((x > y) ? x : y)

Matrix InitializeMatrix(size_t n) {
    Matrix matrix = (Matrix)calloc(n * n, sizeof(Row));
    for (size_t i = 0; i < n; ++i) {
        matrix[i] = (Row)calloc(n, sizeof(int32_t));
    }
    return matrix;
}

Matrix CreateFromFile(const char *filename, size_t *n) {
    FILE *fp = fopen(filename, "r");
    if (fp) {
        // Считываем размер матрицы
        fscanf(fp, "%lu", n);
        if (n == 0) {
            printf("Invalid input\n");
            abort();
        }

        // Инициализируем матрицу
        Matrix matrix = InitializeMatrix(*n);

        // Заполняем матрицу значениями из файла
        for (size_t i = 0; i < *n; ++i) {
            for (size_t j = 0; j < *n; ++j) {
                fscanf(fp, "%d", &matrix[i][j]);
            }
        }

        fclose(fp);

        return matrix;
    } else {
        printf("No such file\n");
        abort();
    }
}

// Длина числа (нужна для форматированного вывода чисел)
size_t NumberLen(int32_t number) {
    if (number == 0) {
        return 1;
    }
    size_t width = 0;
    if (number < 0) {
        ++width;
    }
    number = Abs(number);
    int32_t p10 = 1;
    while (number >= p10) {
        p10 *= 10;
        ++width;
    }
    return width;
}

// Выводит матрицу, в которой все числа выровнены по правому краю
void PrintMatrix(Matrix matrix, size_t n) {
    size_t width = 0;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            width = Max(width, NumberLen(matrix[i][j]) + 1);
        }
    }
    size_t cur_width = 0;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            // Выравнивает по правому краю
            cur_width = NumberLen(matrix[i][j]);
            for (size_t k = 0; k < width - cur_width; ++k) {
                printf(" ");
            }
            // Выводит само число
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Освобождает память
void FreeMatrix(Matrix matrix, size_t n) {
    for (size_t i = 0; i < n; ++i) {
        free(matrix[i]);
    }
    free(matrix);
}

// Заменяет элементы побочной диагонали суммами элементов, проходящих через них главной и других параллельных диагоналей
void Solve(Matrix matrix, size_t n) {
    size_t j = 0;
    size_t x = 0;
    size_t y = 0;
    int32_t new_element = 0;

    for (size_t i = 0; i < n; ++i) {
        new_element = 0;
        j = n - i - 1;
        x = j - i;
        y = 0;
        if (i > j) {
            x = 0;
            y = i - j;
        }
        while (x < n && y < n) {
            new_element += matrix[y][x];
            ++x;
            ++y;
        }
        matrix[i][j] = new_element;
    }
}

int Task() {
    const char *filename = "../tasks/matrix/tasks/8/matrix.txt";  // откуда читаем данные
    size_t n = 0;
    Matrix matrix = CreateFromFile(filename, &n);
    PrintMatrix(matrix, n);

    Solve(matrix, n);
    PrintMatrix(matrix, n);

    FreeMatrix(matrix, n);

    return 0;
}