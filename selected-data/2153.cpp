#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

void f(Intercept<int> i, int m);
// Intercept<int> sum(-1, 3);

Intercept<int> intercepts[] = {Intercept<int>(-1, 3), Intercept<int>(0, 2), Intercept<int>(0, 2), Intercept<int>(0, 4), Intercept<int>(0, 4), Intercept<int>(-1, 5)};
StateIntercept gState(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

int main()
{
      // Intercept<int> n, m, k; //i, 
      scanf("%d", &gState[3]);
      for (gState[1] = Intercept<int>(0, 2); gState[1] < gState[3]; gState[1]++)
      {
            gState[0] = 1;
            gState[5] = 1;
            scanf("%d", &gState[4]);
            f(2, gState[4]);
            printf("%d\n", gState[0]);
      }
}
void f(Intercept<int> i, int m)
{
      Intercept<int> interceptss[] = {Intercept<int>(0, 7)};
      StateIntercept states(interceptss, sizeof(interceptss) / sizeof(interceptss[0]));
      //Intercept<int> s; == states[0]//k, 
      states[0] = (int)sqrt(m);
      for (gState[2] = Intercept<int>(i, 2); gState[2] <= states[0]; gState[2]++)
      {
            if (m % gState[2] == 0)
            {
                  gState[0]++;
                  gState[5]++;
                  f(gState[2], m / gState[2]);
            }
      }
}
