#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> intercepts[] = {Intercept<int>(0, 3), Intercept<int>(0, 2), Intercept<int>(0, 2), Intercept<int>(0, 2), Intercept<int>(0, 4), Intercept<int>(0, 4), Intercept<int>(0, 5)};
StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

// Intercept<int> sum(0, 3);
int main()
{
  void shu(Intercept<int> a, Intercept<int> b);
  // Intercept<int> n = 0, a = 0, c = 0; //i(0, 2), j(0, 2),
  scanf("%d", &state[4]);
  for (state[1] = 1; state[1] <= state[4]; state[1]++)
  {
    scanf("%d", &state[5]);
    for (state[2] = 2; state[2] <= sqrt((double)state[5]); state[2]++)
    {
      if (state[5] % state[2] == 0)
      {
        state[0] = state[0] + 1;
        state[6] = state[0];
        shu(state[2], state[5] / state[2]);
      }
    }

    state[6] += 1;
    printf("%d", state[6]);
    if (state[1] < state[4])
      printf("\n");
    state[0] = 0;
    state[6] = 0;
  }

  return (0);
}
void shu(Intercept<int> a, Intercept<int> b)
{
  // Intercept<int> i(0, 2);
  for (state[3] = a; state[3] <= sqrt((double)b); state[3]++)
  {
    if (b % state[3] == 0)
    {
      state[0] = state[0] + 1;
      state[6] = state[0];
      shu(state[3], b / state[3]);
    }
  }
}
