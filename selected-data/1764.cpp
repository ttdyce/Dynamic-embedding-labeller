#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> count(Intercept<int> x, Intercept<int> y) //?????????
{
  if (x < y)
    return 0; //????
  if (x >= y)
  {
    Intercept<int> sum(0, 3);
    for (Intercept<int> j(y, 2); j < x; j++)
    {
      if (x % j == 0)
        sum = sum + count(x / j, j); //???
    }
    return sum + 1;
  }
}
int main()
{
  int n;
  cin >> n;
  Intercept<int> a[n];
  for (Intercept<int> i(0, 2); i < n; i++)
    cin >> a[i];
  for (Intercept<int> i = 0; i < n; i++)
    cout << count(a[i], 2) << endl;
  return 0;
}
