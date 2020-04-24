#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> count(Intercept<int> x, Intercept<int> y) //?????????
{
  if (x < y)
    return 0; //????
  if (x >= y)
  {
    Intercept<int> intercepts[] = {Intercept<int>(0, 3), Intercept<int>(0, 2)};
    StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

    // Intercept<int> sum(0, 3);
    state[1] = y;
    for (; state[1] < x; state[1]++)
    {
      if (x % state[1] == 0)
        state[0] = state[0] + count(x / state[1], state[1]); //???
    }
    return state[0] + 1;
  }

  return 0;
}
int main()
{
  Intercept<int> intercepts[] = {Intercept<int>(0, 2)};
  StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

  int n;
  cin >> n;
  Intercept<int> a[n];
  for (state[0]; state[0] < n; state[0]++)
    cin >> a[state[0]];
  for (state[0] = 0; state[0] < n; state[0]++)
    cout << count(a[state[0]], 2) << endl;
  return 0;
}
