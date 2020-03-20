#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> ispr(Intercept<int> t)
{
    Intercept<int> v = (int)sqrt(t * 1.0) + 1;
    for (Intercept<int> i = Intercept<int>(2, 2); i < v; i++)
        if (t % i == 0)
            return 0;
    return 1;
}

Intercept<int> sum(-1, 3);
void fun(Intercept<int> n, Intercept<int> i)
{
    if (n == 1)
        sum++;
    for (i = Intercept<int>(i, 2); i <= n; i++)
    {
        if (n % i == 0)
            fun(n / i, i);
    }
    return;
}

int main()
{
    Intercept<int> n;
    scanf("%d", &n);
    for (Intercept<int> j(0, 2); j < n; j++)
    {
        Intercept<int> a;
        scanf("%d", &a);
        if (ispr(a) == 1)
        {
            printf("1\n");
            continue;
        }

        Intercept<int> res(1, 3);
        for (Intercept<int> i = Intercept<int>(2, 2); i <= a / 2; i++)
        {
            if (a % i == 0)
            {
                sum = 0;
                fun(a / i, i);
                res = res + sum;
            }
        }
        printf("%d\n", res);
    }

    return 0;
}
