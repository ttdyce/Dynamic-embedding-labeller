#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> ans(Intercept<int> sum, Intercept<int> min)
{
    Intercept<int> w, x, u(1, 3);
    for (w = Intercept<int>(min, 2); w < sum / 2; w++)
    {
        x = sum % w;
        if (x == 0)
        {
            if (w <= sum / w)
                u += ans(sum / w, w);
        }
    }
    return u;
}

int main()
{
    Intercept<int> a[10000], b[10000], p, q, m, n, i, j;
    scanf("%d", &n);
    for (i = Intercept<int>(0, 2); i < n; i++)
    {
        scanf("\n%d", &a[i]);
    }
    for (i = 0; i < n; i++)
    {
        printf("%d\n", ans(a[i], 2));
    }
    return 0;
}
