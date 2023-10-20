#pragma once

#include <stdbool.h>
#include <stdio.h>

const double INITIAL_VALUE_I = 11;
const double INITIAL_VALUE_J = 13;
const double INITIAL_VALUE_L = 10;
const int MAX_ITERATIONS = 50;
const double SQUARE_CENTER_X = 10;
const double SQUARE_CENTER_Y = 10;
const double SQUARE_EDGE = 10;
const double EIGHT = 8;
const double FIFTEEN = 15;
const double FIVE = 5;
const double FOURTEEN = 14;
const double TEN = 10;
const double THREE = 3;
const double TWENTY = 20;
const int ZERO = 0;

typedef struct {
    double x;
    double y;
} Point;

double Abs(double n) {
    if (n < 0) {
        return -n;
    } else {
        return n;
    }
}

double Max(double a, double b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

double Min(double a, double b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

double Fmod(double a, double b) {
    return (a - (int)(a / Abs(b)) * b);
}

double Truefmod(double a, double b) {
    return Fmod(b + Fmod(a, b), b);
}

int CheckZone(Point p) {
    return (bool)((p.x >= (SQUARE_CENTER_X - SQUARE_EDGE / 2)) && (p.x <= (SQUARE_CENTER_X + SQUARE_EDGE / 2)) &&
                  (p.y >= (SQUARE_CENTER_Y - SQUARE_EDGE / 2)) && (p.y <= (SQUARE_CENTER_Y + SQUARE_EDGE / 2)));
}

int Task() {
    double i = INITIAL_VALUE_I;
    double j = INITIAL_VALUE_J;
    double l = INITIAL_VALUE_L;
    int hit_counter = ZERO;
    Point p;
    p.x = i;
    p.y = j;
    for (int k = 1; k <= MAX_ITERATIONS; ++k) {
        p.x = Abs(k - FIFTEEN) - Min(p.x / THREE, Truefmod(p.y + l, TEN)) - TWENTY;
        p.y = -(p.y + k) / FIVE + Abs(Truefmod(p.x * l, EIGHT));
        l = Max(Truefmod(p.x + p.y, FIFTEEN), Truefmod(l + k, FOURTEEN));
        if (CheckZone(p)) {
            ++hit_counter;
        }
        printf("p.x:%f, p.y:%f, l:%f, hit count:%d\n", p.x, p.y, l, hit_counter);
    }
    if (hit_counter == 0) {
        printf("No points hit square for 50 iterations\n");
    } else if (hit_counter > 0) {
        printf("Points hit counter:%d\n", hit_counter);
    }
    return 0;
}