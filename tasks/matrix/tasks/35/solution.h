#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef int32_t** Matrix;

/* Зададим для простоты структуру координат */

typedef struct {
    int32_t i;
    int32_t j;
} Coordinates;

/* Чтение матрицы из файла, где первые два числа - строки и столбцы матрицы, остальные символы - эл-ты матрицы */

void MatrixReading(Matrix matrix, FILE* matrix_file, int32_t columns, int32_t rows) {
    for (int i = 0; i < rows; ++i) {
        // выделяем место под каждую строчку
        matrix[i] = (int32_t*)malloc(sizeof(int32_t) * columns);
        // записываем эл-ты строки матрицы из файла
        for (int j = 0; j < columns; ++j) {
            fscanf(matrix_file, "%d", &matrix[i][j]);
        }
    }
}

/* Поворот матрицы на 90° против часовой без использования доп матрицы */

void MatrixRotation(Matrix matrix, int32_t side) {
    int32_t amount_of_rotate_square = side - 1;
    int32_t amount_of_squares = side / 2;
    // будем менять эл-ты местами по кругу (по факту это квадратики), при помощи temp
    int32_t temp = 0;
    // возьмем координаты 4х углов матрицы, и будем менять эл-ты матрицы в квадратике.
    // Тут coordinates1 - координаты левого верхнего угла, 2 - левого нижнего, 3 - правого нижнего, 4 - правого верхнего
    Coordinates coordinates1 = {0, 0};
    Coordinates coordinates2 = {side - 1, 0};
    Coordinates coordinates3 = {side - 1, side - 1};
    Coordinates coordinates4 = {0, side - 1};
    // сделаем возможность возвращаться к начальным позиция, не особо парясь, задав угловые позиции кв-та,
    // который находится внутри нашего большого кв-та
    Coordinates coordinates1_backup = {1, 1};
    Coordinates coordinates2_backup = {side - 2, 1};
    Coordinates coordinates3_backup = {side - 2, side - 2};
    Coordinates coordinates4_backup = {1, side - 2};
    // сама функция замены
    for (int k = 0; k < amount_of_squares; ++k) {
        for (int p = 0; p < amount_of_rotate_square; ++p) {
            temp = matrix[coordinates1.i][coordinates1.j];
            matrix[coordinates1.i][coordinates1.j] = matrix[coordinates4.i][coordinates4.j];
            matrix[coordinates4.i][coordinates4.j] = matrix[coordinates3.i][coordinates3.j];
            matrix[coordinates3.i][coordinates3.j] = matrix[coordinates2.i][coordinates2.j];
            matrix[coordinates2.i][coordinates2.j] = temp;
            ++coordinates1.i;
            ++coordinates2.j;
            --coordinates3.i;
            --coordinates4.j;
        }
        amount_of_rotate_square -= 2;
        // переходим к след квадрату
        coordinates1.i = coordinates1_backup.i;
        coordinates1.j = coordinates1_backup.j;
        coordinates2.i = coordinates2_backup.i;
        coordinates2.j = coordinates2_backup.j;
        coordinates3.i = coordinates3_backup.i;
        coordinates3.j = coordinates3_backup.j;
        coordinates4.i = coordinates4_backup.i;
        coordinates4.j = coordinates4_backup.j;
        // меняем бэкапные координыта на координаты квадрата еще меньше
        ++coordinates1_backup.i;
        ++coordinates1_backup.j;
        --coordinates2_backup.i;
        ++coordinates2_backup.j;
        --coordinates3_backup.i;
        --coordinates3_backup.j;
        ++coordinates4_backup.i;
        --coordinates4_backup.j;
    }
}

/* Освобождение памяти */
void FreeingUpMatrixMemory(Matrix matrix, int32_t side) {
    for (int i = 0; i < side; ++i) {
        free(matrix[i]);
    }
    free(matrix);
}

int Task() {
    // открываем файл и заводим кол-во строк и столбцов, тк матрица квадратная, то они равны
    FILE* matrix_file;
    matrix_file = fopen("../tasks/matrix/tasks/35/matrix.txt", "r");
    int32_t columns = 0;
    int32_t rows = 0;
    int32_t side = 0;
    // читаем из файла кол-во строк и столбцов матрицы
    fscanf(matrix_file, "%d", &side);
    rows = side;
    columns = side;
    Matrix matrix = (Matrix)malloc(sizeof(int32_t*) * rows);
    MatrixReading(matrix, matrix_file, columns, rows);
    MatrixRotation(matrix, side);
    for (int k = 0; k < rows; ++k) {
        for (int p = 0; p < columns; ++p) {
            printf("%d ", matrix[k][p]);
        }
        printf("\n");
    }
    FreeingUpMatrixMemory(matrix, side);
    fclose(matrix_file);
    return 0;
}
