#include <stdio.h>

const int ITEREATIONS = 50;
const int CORD_X1 = -10;
const int CORD_X2 = 0;
const int CORD_Y1 = 0;
const int CORD_Y2 = 10;
const int CORD_X3 = -10;
const int CORD_Y3 = 20;
const int MOD_20 = 20;
const int MOD_30 = 30;

typedef struct {
    int x;
    int y;
} Point;

int CheckZone(Point p) {
    int cord_x = p.x;
    int cord_y = p.y;
    if (((cord_y) >= ((cord_x) + CORD_Y2)) && ((cord_y) <= ((-1) * (cord_x) + CORD_Y2)) && (((cord_x) > CORD_X3))) {
        return 1;
    } else {
        return 0;
    }
}

int Abs(int x) {
    if (x > 0) {
        return x;
    } else {
        return x * -1;
    }
}

int Mod(int x, int y) {
    if (y != 0) {
        return x % y;
    } else {
        return 0;
    }
}

int Sign(int x) {
    if (x > 0) {
        return 1;
    }

    if (x < 0) {
        return -1;
    } else {
        return 0;
    }
}

int Maxz(int x, int y) {
    if (x > y) {
        return x;
    } else {
        return y;
    }
}

int Minz(int x, int y) {
    if (x < y) {
        return x;
    } else {
        return y;
    }
}

int Task() {
    const int i_start = -8;
    const int j_start = -5;
    const int l_start = 12;
    int i_0 = i_start;
    int j_0 = j_start;
    int l_0 = l_start;
    for (int i = 0; i < ITEREATIONS; ++i) {
        Point p;
        p.x = i_0;
        p.y = j_0;
        int i_1 = 0;
        int j_1 = 0;
        int l_1 = 0;

        if (CheckZone(p) == 1) {
            printf("x=%d, y=%d k=%d\n", i_0, j_0, i);
        }
        if (i_0 >= i) {
            i_1 = Mod((i_0 ^ 2) / (Abs(j_0 - l_0) + i + 1) - (j_0 ^ 2) / (Abs(i_0 - l_0) + i + 1), MOD_30);
        } else {
            i_1 = Mod((i_0 ^ 2) / (Abs(j_0 - l_0) + i + 1) - (j_0 ^ 2) / (Abs(i_0 - l_0) + i + 1), MOD_30);
        }
        j_1 = Sign(l_0 * Minz(i_0, j_0)) - Sign(j_0 * Maxz(i_0, l_0)) + i;
        l_1 = (i_0 - j_0) * (j_0 - l_0) * Mod(l_0 - i_0, MOD_20);
        i_0 = i_1;
        j_0 = j_1;
        l_0 = l_1;
    }
    return 0;
}
