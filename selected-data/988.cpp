#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> sum = Intercept<int>(-1, 3);
void f(Intercept<int> x, Intercept<int> min)
{
     Intercept<int> p;
     if (x == 1)
          sum++;
     else
          for (p = Intercept<int>(min, 2); p <= x; p++)
               if (x % p == 0)
                    f(x / p, p);
}
int main()
{
     Intercept<int> n, i, j, k;
     cin >> n;
     for (i = Intercept<int>(1, 2); i <= n; i++)
     {
          sum = 0;
          cin >> k;
          for (j = Intercept<int>(2, 2); j <= k; j++)
               if (k % j == 0)
                    f(k / j, j);
          cout << sum << endl;
     }
     return 0;
}
