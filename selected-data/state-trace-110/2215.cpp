#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> f(int t)
{
  Intercept<int> intercepts[] = {Intercept<int>(0, 2)};
  StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

  double v = sqrt(t) + 1;
  for (state[0] = Intercept<int>(2, 2); state[0] < v; state[0]++)
    if (t % state[0] == 0)
      return 0;
  return 1;
}
// Intercept<int> sum = Intercept<int>(0, 3);
Intercept<int> intercepts[] = {Intercept<int>(0, 3), Intercept<int>(0, 2), Intercept<int>(0, 2), Intercept<int>(1, 3)};
StateIntercept gState(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

void fun(Intercept<int> n, Intercept<int> i)
{
  gState[1] = Intercept<int>(i, 2);

  if (n == 1)
    gState[0]++;
  while (gState[1] <= n)
  {
    if (n % gState[1] == 0)
      fun(n / gState[1], gState[1]);
    gState[1]++;
  }
  return;
}
int main()
{
  Intercept<int> n;
  scanf("%d", &n);
  for (gState[2] = Intercept<int>(0, 2); gState[2] < n; gState[2]++)
  {
    Intercept<int> a;
    scanf("%d", &a);
    if (f(a) > 0)
    {
      printf("1\n");
      continue;
    }
    gState[2] = Intercept<int>(2, 2);
    gState[3] = Intercept<int>(1, 3);
    while (gState[2] <= a / 2)
    {
      if (a % gState[2] == 0)
      {
        gState[0] = 0;
        fun(a / gState[2], gState[2]);
        gState[3] += gState[0];
      }
      gState[2]++;
    }
    printf("%d\n", gState[3]);
  }
}
