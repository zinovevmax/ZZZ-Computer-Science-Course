#pragma once

#include <stdio.h>

typedef struct {
    int x;
    int y;
} Point;

const Point Center = {10, 10};
const int radius_of_inner = 5;
const int radius_of_outer = 10;
const int I0 = 26;
const int J0 = 8;
const int L0 = -3;
const int max_iterations = 50;
const int one = 1;
const int ten = 10;
const int twenty = 20;
const int thirty = 30;

double root(double num) {
    if (num == 0) {
        double x1 = 0;
        return x1;
    } else {
        double x0 = num / 2.0;
        double epsilon = 0.000001;
        while (1) {
            double x1 = 0.5 * (x0 + (num / x0));
            if (x1 - x0 > 0) {
                if (x1 - x0 < epsilon) {
                    return x1;
                }
            } else {
                if (-(x1 - x0) < epsilon) {
                    return x1; 
                }
            }
            x0 = x1;
        }
    }
}

int sign(int num) {
    if (num > 0) {
        return 1;
    } else if (num < 0){
        return -1;
    } else {
        return 0;
    }
} 

int max(int first, int second, int third){
    if (first > second) {
        if (first > third) {
            return first;
        } else {
            return third;
        }
    } else {
        if (second > third) {
            return second;
        } else {
            return third;
        }
    } 
}

int min(int first, int second){
    if (first < second) {
        return first;
    } else {
        return second;
        } 
}

int mod(int num, int del){
    return (num % del + del) % del;
}

int ABS(int num){
    if (num > 0) {
        return num;
    } else {
        return -num;
    }
}

int CheckZone(Point p) {
    int projection_on_x = ABS(p.x - Center.x);
    int projection_on_y = ABS(p.y - Center.y);
    int square_of_distance = projection_on_x * projection_on_x + projection_on_y * projection_on_y;
    double distance = root(square_of_distance);
    return (distance <= radius_of_outer && distance >= radius_of_inner);
}

int Task() {
    int is_inside = 0;
    int is_not_inside = 1;
    int i, j;
    int l = L0;
    Point p = {I0, J0};
    for (int k = 1; k <= max_iterations; ++k) {
        i = mod((min(p.x + p.y, p.x + l) * (k + one)), thirty);
        j = p.y + mod(l * sign(p.y), twenty) + mod(k * sign(p.x), ten);
        l = mod(max(p.x * p.y, p.x * l, p.y * l), thirty);
        p.x = i;
        p.y = j;
        is_inside = CheckZone(p);
        if (is_inside) {
            printf("The point fell into the specified area at x = %d, y = %d, l = %d, iteration = %d\n", p.x, p.y, l, is_inside, k);
            is_not_inside = 0;
        } else {
            printf("iteration = %i, x = %i, y = %i, l = %i, result = %i\n", k, p.x, p.y, l, is_inside);
        }
    }
    if (is_not_inside) {
        printf("The point did not hit the area in 50 iterations");
    }
    return 0;
}
