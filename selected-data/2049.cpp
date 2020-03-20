#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> f(int n, Intercept<int> i)
{
    Intercept<int> sum(0, 3);
    for (i = Intercept<int>(i, 2); i <= (int)sqrt(n); i++)
    {
        if (n % i == 0)
        {
            sum += f(n / i, i);
        }
    }
    return sum + 1;
}
main()
{
    Intercept<int> i0, n0;
    scanf("%d", &n0);
    for (i0 = Intercept<int>(0, 2); i0 < n0; i0++)
    {
        Intercept<int> n;
        scanf("%d", &n);
        printf("%d\n", f(n, 2));
    }
}
