#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> k = 2; //sum(0, 3),
Intercept<int> intercepts[] = {Intercept<int>(0, 3), Intercept<int>(0, 3), Intercept<int>(0, 2), Intercept<int>(0, 2), Intercept<int>(0, 4), Intercept<int>(0, 4), Intercept<int>(0, 5)};
StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

Intercept<int> fenjie(Intercept<int> n, Intercept<int> k)
{
  Intercept<int> interceptss[] = {Intercept<int> (0,7), Intercept<int> (0,7)};
  StateIntercept states (interceptss, sizeof(interceptss) / sizeof(interceptss[0]));
  //Intercept<int>  p = 0; == states[1] // sum(0, 3),i,  // x ==states[0]
  states[0] = (int)pow(n, 0.5);
  for (state[2] = Intercept<int>(k, 2); state[2] <= states[0]; state[2]++)
  {
    if (n % state[2] == 0)
    {
      k = state[2];
      state[1] = state[1] + fenjie(n / state[2], k);
      state[6] = state[1];
      states[1] = 1;
    }
  }
  if (states[1] == 0)
    return 1;
  if (states[1] == 1)
  {
    state[6] = state[1] + 1;
    return state[6];
  }

  return 1;
}
int main()
{
  // Intercept<int> m, n; //, i
  cin >> state[4];
  for (state[3] = Intercept<int>(0, 2); state[3] <= state[4] - 1; state[3]++)
  {
    cin >> state[5];
    cout << fenjie(state[5], 2) << endl;
    state[0] = 0;
  }

  return 0;
}
