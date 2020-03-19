#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
#include <string.h>
using namespace std;

void f(Intercept<int> i, int m);
Intercept<int> sum(-1, 3);
int main()
{
      Intercept<int> n, i, m, k;
      scanf("%d", &n);
      for (i = Intercept<int>(0, 2); i < n; i++)
      {
            sum = 1;
            scanf("%d", &m);
            f(2, m);
            printf("%d\n", sum);
      }
}
void f(Intercept<int> i, int m)
{
      Intercept<int> k, s;
      s = (int)sqrt(m);
      for (k = Intercept<int>(i, 2); k <= s; k++)
      {
            if (m % k == 0)
            {
                  sum++;
                  f(k, m / k);
            }
      }
}
