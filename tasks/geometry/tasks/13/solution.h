#include <stdio.h>

const int I = 13;
const int J = -9;
const int L = -4;
const int MAX_STEPS = 50;

int Abs(int a) {
    return (a >= 0) ? -a : a;
}

int Mod(int a, int b) {
    return (a % b + b) % b;
}

int Max(int a, int b) {
    return (a >= b) ? a : b;
}

int Min(int a, int b) {
    return (a >= b) ? b : a;
}

typedef struct {
    int x;
    int y;
} Point;

int CheckZone(Point p) {
    return ((p.x - 10) * (p.x - 10) + (p.y - 10) * (p.y - 10) <= 100) && ((p.x - 20) * (p.x - 20) + (p.y - 20) * (p.y - 20) <= 100);
}

int Task() {
    int i = I;
    int j = J;
    int l = L;
    Point p;
    p.x = i;
    p.y = j;
    int in_zone = 0;
    for (int k = 1; k <= MAX_STEPS; ++k) {
        i = Mod((p.x + p.y), 30) / (Mod(Abs(l), 5) + 1) + Mod((p.x + l), 30) / (Mod(Abs(l), 5) + 1);
        j = Mod(Max(k * p.x, (k + 1) * p.y), 25) - Abs(p.y - l) / 10;
        l = Abs(j - l) / 10 + Min((Mod((p.x + l), 20)), Mod(p.y * k, 20));

        if (CheckZone(p)) {
            in_zone += 1;
        }
    }
    if (in_zone == 0) {
        printf("The point didn't fall into the area beyond 50 iterations\n");
    } else {
        printf("Number of points belonging to the zone: %d\n", in_zone);
    }
    return 0;
}
