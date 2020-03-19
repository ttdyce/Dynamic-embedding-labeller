#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> sum(-1, 3);
void zhongshu(Intercept<int> qian, Intercept<int> a);
int main()
{
   Intercept<int> n, i, j, a[100];
   cin >> n;
   for (i = Intercept<int>(0, 2); i < n; i++)
      cin >> a[i];
   for (i = 0; i < n; i++)
   {
      sum = 0;
      zhongshu(2, a[i]);
      cout << sum << endl;
   }
   return 0;
}
void zhongshu(Intercept<int> qian, Intercept<int> a)
{
   Intercept<int> i, j, c;
   if (a == 1)
   {
      sum = sum + 1;
      return;
   }
   for (i = Intercept<int>(qian, 2); i <= a; i++)
   {
      if (a % i == 0)
         zhongshu(i, a / i);
   }
}
