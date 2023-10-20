#pragma once

#include <stdio.h>

// INITIAL VALUES
const int INITIAL_VALUE_I = 29;
const int INITIAL_VALUE_J = -6;
const int INITIAL_VALUE_L = 1;
const int NUMBER_OF_ITERATIONS = 50;

const int MOD_VALUE = 30;
const int X1 = -10;
const int Y1 = 0;
const int X2 = 0;
const int Y2 = 10;
const int X3 = -10;
const int Y3 = 20;
const int Z = 10;

typedef struct {
    int x;
    int y;
} Point;

int CheckZone(Point p) {
    // Write a code here that checks whether a point belongs to a given area
    return ((p.x >= X1 && p.x <= X2) && (p.y <= -p.x + Z) && (p.y >= p.x + Z));
}

int Abs(int a) {
    return (a >= 0) ? a : -a;
}

int Mod(int a, int b) {
    return Abs(a % b);
}

int MaxValue(int a, int b) {
    return a > b ? a : b;
}

int MinValue(int a, int b) {
    return a < b ? a : b;
}

int Task() {
    // write main code here
    Point p;
    p.x = INITIAL_VALUE_I;
    p.y = INITIAL_VALUE_J;
    int l_val = INITIAL_VALUE_L;

    for (int i = 1; i <= NUMBER_OF_ITERATIONS; ++i) {

        p.x = Mod(MinValue(MaxValue(MinValue(p.x - p.y, p.x - l_val), p.y - l_val), p.x - i), MOD_VALUE);
        p.y = Mod(MaxValue(MinValue(MaxValue(p.x - p.y, p.x - l_val), p.y - l_val), p.y - i), MOD_VALUE);
        l_val = (Mod(p.x, MOD_VALUE)) - (Mod(p.y, MOD_VALUE)) + (Mod(l_val, MOD_VALUE)) - (Mod(i, MOD_VALUE));

        int is_point_hit_zone = CheckZone(p);
        printf("%d: x = %d, y = %d, isPointHitZone = %d\n", i, p.x, p.y, is_point_hit_zone);
    }
    return 0;
}