#include <stdio.h>

const short int ITEREATIONS = 50;
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
    int I_0 = -8, J_0 = -5, L_0 = 12;
    for (int i = 0; i < ITEREATIONS; ++i) {
        Point p;
        p.x = I_0;
        p.y = J_0;
        int I_1 = 0;
        int J_1 = 0;
        int L_1 = 0;

        if (CheckZone(p) == 1) {
            printf("x=%d, y=%d k=%d\n", I_0, J_0, i);
        }
        if (I_0 >= i) {
            I_1 = Mod((I_0 ^ 2) / (Abs(J_0 - L_0) + i + 1) - (J_0 ^ 2) / (Abs(I_0 - L_0) + i + 1), MOD_30);
        } else {
            I_1 = Mod((I_0 ^ 2) / (Abs(J_0 - L_0) + i + 1) - (J_0 ^ 2) / (Abs(I_0 - L_0) + i + 1), MOD_30);
        }
        J_1 = Sign(L_0 * Minz(I_0, J_0)) - Sign(J_0 * Maxz(I_0, L_0)) + i;
        L_1 = (I_0 - J_0) * (J_0 - L_0) * Mod(L_0 - I_0, MOD_20);
        I_0 = I_1;
        J_0 = J_1;
        L_0 = L_1;
    }
    return 0;
}
