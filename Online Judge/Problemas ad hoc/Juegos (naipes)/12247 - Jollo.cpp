#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, c, x, y;

    while (scanf("%d %d %d %d %d", &a, &b, &c, &x, &y), !(a == 0 && b == 0 && c == 0 &&
        x == 0 && y == 0))
    {
        bool cartas[55] = {0};
        cartas[a] = cartas[b] = cartas[c] = true;
        cartas[x] = cartas[y] = true;

        if (b > a)
        {
            swap(a, b);
        }
        if (c > a)
        {
            swap(a, c);
        }
        if (c > b)
        {
            swap(b, c);
        }

        if (y > x)
        {
            swap(x, y);
        }

        int z = 53;

        if (y > a)
        {
            z = 1;
        }
        else if ((y > b))
        {
            z = b + 1;
        }
        else if ((x > a))
        {
            z = a + 1;
        }

        while (z <= 52)
        {
            if (cartas[z])
            {
                z++;
            }
            else
            {
                break;
            }
        }

        z = (z == 53) ? -1 : z;
        printf("%d\n", z);
    }

    return 0;
}