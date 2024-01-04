#pragma once

#include <stdio.h>
#include <stdlib.h>

#define ROWS 4
#define COLS 4

void AllocateMarix(int*** matrix) {
    *matrix = (int**)malloc(ROWS * sizeof(int*));
    for (int i = 0; i < ROWS; i++) {
        (*matrix)[i] = (int*)malloc(COLS * sizeof(int));
    }
}

void FreeMatrix(int** matrix) {
    for (int i = 0; i < ROWS; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void InitializeMatrix(int** matrix, int rows, int cols) {
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


void Lineralize(int** matrix) {
    for (int i = 0; i < ROWS + COLS - 1; i++) {
        int row, col;
        if (i < COLS) {
            row = 0;
            col = COLS - 1 - i;
        }
        else {
            row = i - COLS + 1;
            col = 0;
        }

        int diagonal[ROWS < COLS ? ROWS : COLS];
        int diagonal_length = 0;
        while (row < ROWS && col < COLS) {
            diagonal[diagonal_length++] = matrix[row][col];
            row++;
            col++;
        }

        if (i % 2 != 0) {
            for (int j = diagonal_length - 1; j >= 0; j--) {
                printf("%d ", diagonal[j]);
            }
        }
        else {
            for (int j = 0; j < diagonal_length; j++) {
                printf("%d ", diagonal[j]);
            }
        }
    }
}

int Task() {
    int** matrix;
    allocate_matrix(&matrix);
    initialize_matrix(matrix, ROWS, COLS);
    print_matrix_diagonals(matrix);
    free_matrix(matrix);
    return 0;
}
