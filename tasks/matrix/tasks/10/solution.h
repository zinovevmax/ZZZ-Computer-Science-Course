#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef int32_t** Matrix;

Matrix CreateMatrix(int32_t n) {
    Matrix matrix = (Matrix)malloc(n * sizeof(int32_t*));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int32_t*)malloc(n * sizeof(int32_t));
    }
    return matrix;
}

void MatrixFree(Matrix matrix, int32_t n) {
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void ShiftColumnsGroup(Matrix matrix, int32_t n, int32_t group, int32_t shift) {
    shift %= n;

    for (int i = 0; i < n; i++) {
        int32_t temp = matrix[i][group];
        for (int j = group; j < group + shift; j++) {
            if (j + shift < n) {
                matrix[i][j] = matrix[i][j + shift];
            }
        }
        matrix[i][(group + shift) % n] = temp;
    }
}

void ShiftAllColumnsGroups(Matrix matrix, int32_t n, int32_t groupSize, int32_t shift) {
    for (int32_t group = 0; group < n; group += groupSize) {
        ShiftColumnsGroup(matrix, n, group, shift);
    }
}

void PrintMatrix(Matrix matrix, int32_t n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[j][i]);
        }
        printf("\n");
    }
}

Matrix InitializeMatrixAndShift(const char* filename, int32_t* n) {
    int32_t matrixShift = 3; // можно поменять на подходящее значение
    if (matrixShift < 0) {
        printf("Invalid input\n");
        abort();
    }
    FILE* file = fopen(filename, "r");
    fscanf(file, "%d", n);
    int32_t matrixSize = (*n) * (*n);
    if (matrixShift > matrixSize) {
        matrixShift = matrixShift % matrixSize;
    }
    Matrix matrix = CreateMatrix(*n);
    int32_t* startElements = (int32_t*)malloc((matrixSize - matrixShift) * sizeof(int32_t));
    int32_t readElementsMatrixCounter = matrixSize;
    int32_t newElementsCount = 0;
    for (int i = 0; i < matrixSize - matrixShift; ++i) {
        fscanf(file, "%d", &startElements[i]);
    }
    for (int i = 0; i < *n; ++i) {
        for (int j = 0; j < *n; ++j) {
            if (readElementsMatrixCounter > matrixSize - matrixShift) {
                fscanf(file, "%d", &matrix[i][j]);
            } else if (readElementsMatrixCounter <= matrixSize - matrixShift) {
                matrix[i][j] = startElements[newElementsCount];
                ++newElementsCount;
            }
            --readElementsMatrixCounter;
        }
    }
    fclose(file);
    free(startElements);
    return matrix;
}

int Task() {
    int32_t n = 0;
    const char* filename = "../tasks/matrix/tasks/10/matrix.txt";
    Matrix matrix = InitializeMatrixAndShift(filename, &n);
    int32_t groupSize = 1; // можно поменять на подходящее значение
    int32_t shift = 3; // можно поменять на подходящее значение
    ShiftAllColumnsGroups(matrix, n, groupSize, shift);
    PrintMatrix(matrix, n);
    MatrixFree(matrix, n);
    return 0;
}
