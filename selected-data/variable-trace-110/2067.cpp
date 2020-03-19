#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> n, m;
Intercept<int> sum(Intercept<int> x, int y)
{
    Intercept<int> c(-1, 3), i;
    if (x > sqrt(y))
        c = 0;
    else
    {
        if (y % x == 0)
        {
            for (i = Intercept<int>(x, 2), c = 1; i <= (y / 2) + 1; i++)
            {
                if ((y / x) % i == 0)
                    c = c + sum(i, (y / x));
            }
        }
        else
            c = 0;
    }
    return (c);
}
main()
{
    Intercept<int> i, k, j;
    scanf("%d", &n);
    for (j = Intercept<int>(1,2); j <= n; j++)
    {
        k = 0;
        scanf("%d", &m);
        for (i = Intercept<int>(2, 2); i <= (m / 2) + 1; i++)
            k = k + sum(i, m);
        printf("%d\n", k + 1);
    }
}
