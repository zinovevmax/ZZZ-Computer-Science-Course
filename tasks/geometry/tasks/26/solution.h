#pragma once

#include <stdio.h>

const int initial_value_i = -10;
const int initial_value_j = -10;
const int initial_value_l = 6;
const int center_coordinates_y = 0;
const int center_coordinates_x = 20;
const int coordinates_a_x = 10;
const int coordinates_b_x = 30;
const int coordinates_c_y = 5;
const int coordinates_d_y = -5;
const int max_iterations = 50;
const int thirty = 30;
const int twenty_five = 25;
const int ten = 10;
const int thirty_five = 35;
const int zero = 0;
const int one = 1;

int Abs(int a) {
    return (a >= 0) ? a : -a;
}

int Max(int a, int b) {
    return (a >= b) ? a : b;
}

int Min(int a, int b) {
    return (a >= b) ? b : a;
}

int Mod(int a, int b) {
    if (b != 0) {
        return (Abs(a % b));
    } else {
        printf("Error: you can't divide by zero");
    	return 0;
    }
}

typedef struct {
    int x;
    int y;
} Point;

int CheckZone(Point p) {
    return (((p.x - center_coordinates_x) * (p.x - center_coordinates_x)) /
                    ((center_coordinates_x - coordinates_a_x) * (center_coordinates_x - coordinates_a_x)) +
                ((p.y - center_coordinates_y) * (p.y - center_coordinates_y)) /
                    ((center_coordinates_y - coordinates_d_y) * (center_coordinates_y - coordinates_d_y)) <=
            1);
}

int Task() {
    int i = initial_value_i;
    int j = initial_value_j;
    int l = initial_value_l;
    int flag_if_xy_not_inside = zero;
    Point p;
    p.x = i;
    p.y = j;
    for (int k = 1; k <= max_iterations; ++k) {
        p.x = Abs(Max(Mod(Min(p.x + p.y, p.x + l), thirty), Mod(Max(p.x + l, p.y + k), twenty_five)));
        p.y = Mod(Abs(p.x + k), ten) + Mod(Abs(p.y + k), ten) + Mod(Abs(l + k), ten);
        l = Mod(p.x * p.x * p.x + p.y * p.y * p.y + l * l * l - k, thirty_five);
        if (CheckZone(p)) {
            printf("x = %d, y = %d, l = %d, result = YES, number of iteration = %d\n", p.x, p.y, l, k);
            flag_if_xy_not_inside = one;
        } else {
            printf("x = %d, y = %d, l = %d, result = NO\n", p.x, p.y, l);
        }
    }
    if (flag_if_xy_not_inside == zero) {
	printf("50 iterations have elapsed and the point has not entered the zone");
    }
    return 0;
}
