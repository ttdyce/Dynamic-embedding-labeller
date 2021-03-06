#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

void f(Intercept<int> i, int m);
// Intercept<int> sum(-1, 3);

Intercept<int> intercepts[] = {Intercept<int>(-1, 3), Intercept<int>(0, 2), Intercept<int>(0, 2)};
StateIntercept gState(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

int main()
{
      Intercept<int> n, m, k; //i, 
      scanf("%d", &n);
      for (gState[1] = Intercept<int>(0, 2); gState[1] < n; gState[1]++)
      {
            gState[0] = 1;
            scanf("%d", &m);
            f(2, m);
            printf("%d\n", gState[0]);
      }
}
void f(Intercept<int> i, int m)
{
      Intercept<int> s;//k, 
      s = (int)sqrt(m);
      for (gState[2] = Intercept<int>(i, 2); gState[2] <= s; gState[2]++)
      {
            if (m % gState[2] == 0)
            {
                  gState[0]++;
                  f(gState[2], m / gState[2]);
            }
      }
}
