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
const int Max_iterations = 50;
const int one = 1;
const int ten = 10;
const int twenty = 20;
const int thirty = 30;

int Sign(int num) {
    if (num > 0) {
        return 1;
    } else if (num < 0){
        return -1;
    } else {
        return 0;
    }
} 

int Max(int first, int second, int third){
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

int Min(int first, int second){
    if (first < second) {
        return first;
    } else {
        return second;
        } 
}

int Mod(int num, int del){
    return (num % del + del) % del;
}

int Abs(int num){
    if (num > 0) {
        return num;
    } else {
        return -num;
    }
}

int CheckZone(Point p) {
    int projection_on_x = Abs(p.x - Center.x);
    int projection_on_y = Abs(p.y - Center.y);
    int square_of_distance = projection_on_x * projection_on_x + projection_on_y * projection_on_y;
    return (square_of_distance <= radius_of_outer * radius_of_outer && square_of_distance >= radius_of_inner * radius_of_inner);
}

int Task() {
    int is_inside = 0;
    int is_not_inside = 1;
    int i, j;
    int l = L0;
    Point p = {I0, J0};
    for (int k = 1; k <= Max_iterations; ++k) {
        i = Mod((Min(p.x + p.y, p.x + l) * (k + one)), thirty);
        j = p.y + Mod(l * Sign(p.y), twenty) + Mod(k * Sign(p.x), ten);
        l = Mod(Max(p.x * p.y, p.x * l, p.y * l), thirty);
        p.x = i;
        p.y = j;
        is_inside = CheckZone(p);
        if (is_inside) {
            printf("The point fell into the specified area at x = %d, y = %d, l = %d, iteration = %d\n", p.x, p.y, l, k);
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
