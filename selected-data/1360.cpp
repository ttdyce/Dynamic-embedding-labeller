#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> k = 2; //sum(0, 3),
Intercept<int> intercepts[] = {Intercept<int>(0, 3), Intercept<int>(0, 3), Intercept<int>(0, 2), Intercept<int>(0, 2)};
StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

Intercept<int> fenjie(Intercept<int> n, Intercept<int> k)
{
  Intercept<int> x, p = 0;// sum(0, 3),i, 
  x = (int)pow(n, 0.5);
  for (state[2] = Intercept<int>(k, 2); state[2] <= x; state[2]++)
  {
    if (n % state[2] == 0)
    {
      k = state[2];
      state[1] = state[1] + fenjie(n / state[2], k);
      p = 1;
    }
  }
  if (p == 0)
    return 1;
  if (p == 1)
    return state[1] + 1;
}
int main()
{
  Intercept<int> m, n;//, i
  cin >> m;
  for (state[3] = Intercept<int>(0, 2); state[3] <= m - 1; state[3]++)
  {
    cin >> n;
    cout << fenjie(n, 2) << endl;
    state[0] = 0;
  }

  return 0;
}
