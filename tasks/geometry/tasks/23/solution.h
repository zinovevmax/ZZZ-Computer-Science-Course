#pragma once

#include <stdio.h>
#include <stdint.h>

typedef struct {
    int32_t x;
    int32_t y;
} Point;

int CheckZone(Point p) {
    // Write a code here that checks whether a point belongs to a given area
    if ((p.x >= -10 && p.x <= 0) && (p.y <= (-1) * p.x + 10) && (p.y >= p.x + 10)) {
        return 1;
    } else {
        return 0;
    }
}

int32_t MaxValue(int32_t a, int32_t b) {
    return a > b ? a : b;
}

int32_t MinValue(int32_t a, int32_t b) {
    return a < b ? a : b;
}

int Task() {
    // write main code here

    int32_t si = 29;
    int32_t sj = -6;
    int32_t sl = 1;
    size_t number_of_iterations = 50;
    for (size_t i = 0; i < number_of_iterations; ++i) {

        int32_t new_i = MinValue(MaxValue(MinValue(si - sj, sj - sl), sj - sl), si - i) % 30;
        int32_t new_j = MaxValue(MinValue(MaxValue(si - sj, si - sl), sj - sl), si - i) % 30;
        int32_t new_l = (si % 30) - (sj % 30) + (sl % 30) - (i % 30);

        Point p;
        p.x = new_i;
        p.y = new_j;

        int isPointHitZone = CheckZone(p);
        printf("%lu: x = %d, y = %d, isPointHitZone = %d\n", i, p.x, p.y, isPointHitZone);

        si = new_i;
        sj = new_j;
        sl = new_l;

    }
    return 0;
}