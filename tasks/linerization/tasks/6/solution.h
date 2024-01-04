#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define ROWS 4
#define COLS 4

void AllocateMarix(int_32*** matrix) {
    *matrix = (int_32**)malloc(ROWS * sizeof(int_32*));
    for (int_32 i = 0; i < ROWS; i++) {
        (*matrix)[i] = (int_32*)malloc(COLS * sizeof(int_32));
    }
}

void FreeMatrix(int_32** matrix) {
    for (int_32 i = 0; i < ROWS; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void InitializeMatrix(int_32** matrix, int_32 rows, int_32 cols) {
    matrix[0][0] = 10;
    matrix[0][1] = 4;
    matrix[0][2] = 3;
    matrix[0][3] = 1;
    matrix[1][0] = 11;
    matrix[1][1] = 9;
    matrix[1][2] = 5;
    matrix[1][3] = 2;
    matrix[2][0] = 15;
    matrix[2][1] = 12;
    matrix[2][2] = 8;
    matrix[2][3] = 6;
    matrix[3][0] = 16;
    matrix[3][1] = 14;
    matrix[3][2] = 13;
    matrix[3][3] = 7;
}


void Lineralize(int_32** matrix) {
    for (int_32 i = 0; i < ROWS + COLS - 1; i++) {
        int_32 row, col;
        if (i < COLS) {
            row = 0;
            col = COLS - 1 - i;
        }
        else {
            row = i - COLS + 1;
            col = 0;
        }

        int_32 diagonal[ROWS < COLS ? ROWS : COLS];
        int_32 diagonal_length = 0;
        while (row < ROWS && col < COLS) {
            diagonal[diagonal_length++] = matrix[row][col];
            row++;
            col++;
        }

        if (i % 2 != 0) {
            for (int_32 j = diagonal_length - 1; j >= 0; j--) {
                printf("%d ", diagonal[j]);
            }
        }
        else {
            for (int_32 j = 0; j < diagonal_length; j++) {
                printf("%d ", diagonal[j]);
            }
        }
    }
}

int_32 Task() {
    int_32** matrix;
    AllocateMatrix(&matrix);
    InitializeMatrix(matrix, ROWS, COLS);
    Lineralize(matrix);
    FreeMatrix(matrix);
    return 0;
}
