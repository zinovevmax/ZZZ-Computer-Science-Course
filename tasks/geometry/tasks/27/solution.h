#include <stdio.h>

const int Iterations = 50;
const int num_20 = 20;
const int num_35 = 30;
const int num_1 = 1;
const float num_001 = 0.01;
const float num_004 = 0.04;

typedef struct
{
    int x;
    int y;
} Point;

int CheckZone(Point p)
{
    float x_1 = p.x;
    float y_1 = p.y;

    if (((((x_1 - num_20) * (x_1 - num_20)) * (num_001)) + ((y_1 * y_1) * (num_004))) <= (num_1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Abs(int x)
{
    if (x > 0)
    {
        return x;
    }
    else
    {
        return x * -1;
    }
}

int Mod(int x, int y)
{
    if (y > 0)
    {
        return x % y;
    }
    else
    {
        return y - Abs(x);
    }
}

int Max(int x, int y)
{
    if (x > y)
    {
        return x;
    }
    else
    {
        return y;
    }
}

int Min(int x, int y)
{
    if (x < y)
    {
        return x;
    }
    else
    {
        return y;
    }
}

int Sign(int x)
{
    if (x > 0)
    {
        return 1;
    }
    if (x == 0)
    {
        return 0;
    }
    if (x < 0)
    {
        return -1;
    }
}

int main()
{
    int i_1 = -24;
    int j_1 = 4;
    int l_1 = -3;
    int i = i_1;
    int j = j_1;
    int l = l_1;

    for (int k = 0; k < Iterations; k++)
    {
        Point p;
        p.x = i;
        p.y = j;
        int ik = 0;
        int jk = 0;
        int lk = 0;

        if (CheckZone(p) == 1)
        {
            printf("x = %d, y = %d, k = %d \n", i, j, k);
            break;
        }

        ik = Mod(((Abs(i + k)) * (j + (2 * k)) * (l + (3 * k))), num_35);
        jk = (Sign(Max(i, j))) * (Min(Mod(i + k, num_20), Mod(j + l, num_20)));
        lk = (i / 3) - ((Abs(i - k)) * (Sign(l - j)));
        i = ik;
        j = jk;
        l = lk;
    }

    return 0;
}
