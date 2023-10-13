#pragma once

#include <stdio.h>

const short int ITEREATIONS = 50;
const int cord_X1 = -10;
const int cord_X2 = 0;
const int cord_Y1 = 0;
const int cord_Y2 = 10;
const int cord_X3 = -10;
const int cord_Y3 = 20;

typedef struct {
    int x;
    int y;
} Point;

int abs(int x) {
    if (x > 0) {
        return x;
    } else {
        return x * -1;
    }

}

int CheckZone(Point p) {
    int cord_x = p.x, cord_y = p.y;
    if (((cord_y - cord_Y1) >= ((cord_x - cord_X1) + 10)) && ((cord_y - cord_Y2) <= ((-1) * (cord_x - cord_X2) + 10)) &&
        (((cord_x - cord_X3) > -10))) {
        return 1;
    } else {
        return 2;
    }
}


int mod(int x, int y) {
    if (y != 0) {
        return x % y;
    } else {
        return 0;
    }
}

int SIGN(int x) {
    if (x > 0) {
        return 1;
    }

    if (x < 0) {
        return -1;
    } else {
        return 0;
    }
}

int maxz(int x, int y) {
    if (x > y) {
        return x;
    } else {
        return y;
    }
}

int minz(int x, int y) {
    if (x < y) {
        return x;
    } else {
        return y;
    }
}

int main() {
    int i_0 = -8, j_0 = -5, l_0 = 12;
    for (int i = 0; i < ITEREATIONS; ++i) {
        Point p;
        p.x = i_0;
        p.y = j_0;
        int i_1 = 0;
        int j_1 = 0;
        int l_1 = 0;
        if (CheckZone(p) == 1) {
            printf("x=%d, y=%d\n", i_0, j_0);
        }
        if (i_0 >= i) {
            i_1 = mod((i_0 ^ 2) / (abs(j_0 - l_0) + i + 1) - (j_0 ^ 2) / (abs(i_0 - l_0) + i + 1), 30);
        } else {
            i_1 = mod((i_0 ^ 2) / (abs(j_0 - l_0) + i + 1) - (j_0 ^ 2) / (abs(i_0 - l_0) + i + 1), 30);
        }
        j_1 = SIGN(l_0 * minz(i_0, j_0)) - SIGN(j_0 * maxz(i_0, l_0)) + i;
        l_1 = (i_0 - j_0) * (j_0 - l_0) * mod(l_0 - i_0, 20);
        i_0 = i_1;
        j_0 = j_1;
        l_0 = l_1;
    }


    return 0;

}

