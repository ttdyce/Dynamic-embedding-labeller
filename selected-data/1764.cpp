#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> count(Intercept<int> x, Intercept<int> y) //?????????
{
  Intercept<int> intercepts[] = {Intercept<int>(0, 3), Intercept<int>(0, 2), Intercept<int>(0, 8), Intercept<int>(0, 8), Intercept<int>(0, 5)};
  StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));
  if (x < y)
  {
    state[2] = 1;
    return 0; //????
  }
  if (x >= y)
  {

    // Intercept<int> sum(0, 3);
    state[1] = y;
    for (; state[1] < x; state[1]++)
    {
      if (x % state[1] == 0)
      {
        state[0] = state[0] + count(x / state[1], state[1]); //???
        state[4] = state[0];
      }
    }
    state[4] += 1;
    return state[4];
  }

  state[3] = 1;
  return 0;
}
int main()
{
  Intercept<int> intercepts[] = {Intercept<int>(0, 2), Intercept<int>(0, 4)};
  StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

  cin >> state[1];
  int n = state[1];
  Intercept<int> a[n];
  for (state[0]; state[0] < state[1]; state[0]++)
    cin >> a[state[0]];
  for (state[0] = 0; state[0] < state[1]; state[0]++)
    cout << count(a[state[0]], 2) << endl;
  return 0;
}
