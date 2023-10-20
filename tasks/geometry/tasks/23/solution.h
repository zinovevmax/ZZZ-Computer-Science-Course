#pragma once

#include <stdint.h>
#include <stdio.h>

// INITIAL VALUES
const int32_t INITIAL_VALUE_I = 29;
const int32_t INITIAL_VALUE_J = -6;
const int32_t INITIAL_VALUE_L = 1;
const int32_t NUMBER_OF_ITERATIONS = 50;

const int32_t MOD_VALUE = 30;
const int32_t x1 = -10;
const int32_t y1 = 0;
const int32_t x2 = 0;
const int32_t y2 = 10;
const int32_t x3 = -10;
const int32_t y3 = 20;
const int32_t z = 10;

typedef struct {
    int32_t x;
    int32_t y;
} Point;

int CheckZone(Point p) {
    // Write a code here that checks whether a point belongs to a given area
    return ((p.x >= x1 && p.x <= x2) && (p.y <= -p.x + z) && (p.y >= p.x + z));
}

int32_t Abs(int32_t a) {
    return (a >= 0) ? a : -a;
}

int32_t Mod(int32_t a, int32_t b) {
    return Abs(a % b);
}

int32_t MaxValue(int32_t a, int32_t b) {
    return a > b ? a : b;
}

int32_t MinValue(int32_t a, int32_t b) {
    return a < b ? a : b;
}

int Task() {
    // write main code here
    Point p;
    p.x = INITIAL_VALUE_I;
    p.y = INITIAL_VALUE_J;
    int32_t l_val = INITIAL_VALUE_L;

    for (size_t i = 1; i <= NUMBER_OF_ITERATIONS; ++i) {

        p.x = Mod(MinValue(MaxValue(MinValue(p.x - p.y, p.x - l_val), p.y - l_val), p.x - i), MOD_VALUE);
        p.y = Mod(MaxValue(MinValue(MaxValue(p.x - p.y, p.x - l_val), p.y - l_val), p.y - i), MOD_VALUE);
        l_val = (Mod(p.x, MOD_VALUE)) - (Mod(p.y, MOD_VALUE)) + (Mod(l_val, MOD_VALUE)) - (Mod(i, MOD_VALUE));

        int is_point_hit_zone = CheckZone(p);
        printf("%lu: x = %d, y = %d, isPointHitZone = %d\n", i, p.x, p.y, is_point_hit_zone);
    }
    return 0;
}