#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> sum(0, 3), k = 2;
Intercept<int> fenjie(Intercept<int> n, Intercept<int> k)
{
  Intercept<int> x, i, sum(0, 3), p = 0;
  x = (int)pow(n, 0.5);
  for (i = Intercept<int>(k, 2); i <= x; i++)
  {
    if (n % i == 0)
    {
      k = i;
      sum = sum + fenjie(n / i, k);
      p = 1;
    }
  }
  if (p == 0)
    return 1;
  if (p == 1)
    return sum + 1;
}
int main()
{
  Intercept<int> m, n, i;
  cin >> m;
  for (i = Intercept<int>(0, 2); i <= m - 1; i++)
  {
    cin >> n;
    cout << fenjie(n, 2) << endl;
    sum = 0;
  }

  return 0;
}
