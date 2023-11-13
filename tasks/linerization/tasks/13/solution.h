#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

const int32_t MATRIX_SIZE = 16;
const int32_t MATRIX_STRINGS = 4;
const int32_t MATRIX_COLUMNS = 4;
typedef int32_t** Matrix;

int Task() {
    int32_t matrix[4][4] = {{15, 13, 7, 1}, {14, 6, 2, 10}, {5, 3, 9, 11}, {4, 8, 12, 16}};
    int32_t* ans = (int32_t*)malloc(sizeof(int32_t) * MATRIX_SIZE);
    int32_t arr[16] = {4, 7, 10, 13, 9, 6, 3, 14, 11, 8, 12, 15, 2, 5, 1, 16};
    for (int32_t i = 0; i < MATRIX_SIZE; ++i) {
        int32_t elem_pos = arr[i];
        ans[i] = *(matrix[(elem_pos - 1) / MATRIX_COLUMNS] + ((elem_pos - 1) % MATRIX_COLUMNS));
    }
    for (int i = 0; i < MATRIX_SIZE; ++i) {
        printf("%d ", ans[i]);
    }
    free(ans);
    return 0;
}
