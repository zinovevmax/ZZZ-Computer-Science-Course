#include <stdio.h>

const int MAX_ITERATIONS = 50;
const int NUM_20 = 20;
const int NUM_35 = 30;
const int NUM_1 = 1;
const float NUM_001 = 0.01;
const float NUM_004 = 0.04;
const int I_1 = -24;
const int J_1 = 4;
const int L_1 = -3;

typedef struct {
    int x;
    int y;
} Point;

int CheckZone(Point p) {
    int x_1 = p.x;
    int y_1 = p.y;
    float x_p = 0.0;
    float y_p = 0.0;
    float x_1_f = (float)x_1;
    float y_1_f = (float)y_1;
    float num_20_f = (float)NUM_20;
    float num_1_f = (float)NUM_1;

    x_p = (x_1_f - num_20_f) * (x_1_f - num_20_f);
    y_p = y_1_f * y_1_f;
    return ((((x_p) * (NUM_001)) + ((y_p) * (NUM_004))) <= (num_1_f));
}

int Abs(int x) {
    if (x > 0) {
        return x;
    } else {
        return x * -1;
    }
}

int Mod(int x, int y) {
    if (y > 0) {
        return x % y;
    } else {
        return y - Abs(x);
    }
}

int Max(int x, int y) {
    if (x > y) {
        return x;
    } else {
        return y;
    }
}

int Min(int x, int y) {
    if (x < y) {
        return x;
    } else {
        return y;
    }
}

int Sign(int x) {
    if (x > 0) {
        return 1;
    }
    if (x == 0) {
        return 0;
    }
    if (x < 0) {
        return -1;
    }
}

int Task() {
    int i = I_1;
    int j = J_1;
    int l = L_1;

    for (int k = 0; k < MAX_ITERATIONS; ++k) {
        Point p;
        p.x = i;
        p.y = j;
        int ik = 0;
        int jk = 0;
        int lk = 0;

        if (CheckZone(p) == 1) {
            printf("x = %d, y = %d, k = %d \n", i, j, k);
            break;
        }

        ik = Mod(((Abs(i + k)) * (j + (2 * k)) * (l + (3 * k))), NUM_35);
        jk = (Sign(Max(i, j))) * (Min(Mod(i + k, NUM_20), Mod(j + l, NUM_20)));
        lk = (i / 3) - ((Abs(i - k)) * (Sign(l - j)));
        i = ik;
        j = jk;
        l = lk;
    }
    return 0;
}
