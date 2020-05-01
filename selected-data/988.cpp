#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

// Intercept<int> sum = Intercept<int>(-1, 3);
Intercept<int> intercepts[] = {Intercept<int>(-1, 3), Intercept<int>(0, 2), Intercept<int>(1, 2), Intercept<int>(2, 2), Intercept<int>(0, 4), Intercept<int>(0, 4)};
StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

void f(Intercept<int> x, Intercept<int> min)
{
     // Intercept<int> p;
     if (x == 1)
          state[0]++;
     else
          for (state[1] = Intercept<int>(min, 2); state[1] <= x; state[1]++)
               if (x % state[1] == 0)
                    f(x / state[1], state[1]);
}
int main()
{
     // Intercept<int> n,  k;//i, j,
     cin >> state[4];
     for (state[2] = Intercept<int>(1, 2); state[2] <= state[4]; state[2]++)
     {
          state[0] = 0;
          cin >> state[5];
          for (state[3] = Intercept<int>(2, 2); state[3] <= state[5]; state[3]++)
               if (state[5] % state[3] == 0)
                    f(state[5] / state[3], state[3]);
          cout << state[0] << endl;
     }
     return 0;
}
