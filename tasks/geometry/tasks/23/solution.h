#pragma once

#include <stdint.h>
#include <stdio.h>

const int32_t x1 = -10;
const int32_t y1 = 0;
const int32_t x2 = 0;
const int32_t y2 = 10;
const int32_t x3 = -10;
const int32_t y3 = 20;

typedef struct {
    int32_t x;
    int32_t y;
} Point;

int CheckZone(Point p) {
    // Write a code here that checks whether a point belongs to a given area
    if ((p.x >= x1 && p.x <= x2) && (p.y <= (-1) * p.x + 10) && (p.y >= p.x + 10)) {
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
    const int32_t start_i = 29;
    const int32_t start_j = -6;
    const int32_t start_l = 1;
    const size_t number_of_iterations = 50;

    int32_t si = start_i;
    int32_t sj = start_j;
    int32_t sl = start_l;
    
    for (size_t i = 0; i < number_of_iterations; ++i) {

        int32_t new_i = MinValue(MaxValue(MinValue(si - sj, sj - sl), sj - sl), si - i) % 30;
        int32_t new_j = MaxValue(MinValue(MaxValue(si - sj, si - sl), sj - sl), si - i) % 30;
        int32_t new_l = (si % 30) - (sj % 30) + (sl % 30) - (i % 30);

        Point p;
        p.x = new_i;
        p.y = new_j;

        int is_point_hit_zone = CheckZone(p);
        printf("%lu: x = %d, y = %d, isPointHitZone = %d\n", i, p.x, p.y, is_point_hit_zone);

        si = new_i;
        sj = new_j;
        sl = new_l;
    }
    return 0;
}