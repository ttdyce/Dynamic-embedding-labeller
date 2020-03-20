#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> sum(0, 3);
int main()
{
  void shu(Intercept<int> a, Intercept<int> b);
  Intercept<int> n = 0, i(0, 2), a = 0, c = 0, j(0, 2);
  scanf("%d", &n);
  for (i = 1; i <= n; i++)
  {
    scanf("%d", &a);
    for (j = 2; j <= sqrt((double)a); j++)
    {
      if (a % j == 0)
      {
        sum = sum + 1;
        shu(j, a / j);
      }
    }

    printf("%d", sum + 1);
    if (i < n)
      printf("\n");
    sum = 0;
  }

  return (0);
}
void shu(Intercept<int> a, Intercept<int> b)
{
  Intercept<int> i(0, 2);
  for (i = a; i <= sqrt((double)b); i++)
  {
    if (b % i == 0)
    {
      sum = sum + 1;
      shu(i, b / i);
    }
  }
}
