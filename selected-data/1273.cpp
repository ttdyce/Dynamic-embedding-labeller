#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

// Intercept<int> sum(-1, 3);
Intercept<int> intercepts[] = {Intercept<int>(-1, 3), Intercept<int>(0, 2), Intercept<int>(0, 2), Intercept<int>(0, 4)};
StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

void zhongshu(Intercept<int> qian, Intercept<int> a);
int main()
{
   Intercept<int> j, a[100]; // i, n,
   cin >> state[3];
   for (state[1] = Intercept<int>(0, 2); state[1] < state[3]; state[1]++)
      cin >> a[state[1]];
   for (state[1] = 0; state[1] < state[3]; state[1]++)
   {
      state[0] = 0;
      zhongshu(2, a[state[1]]);
      cout << state[0] << endl;
   }
   return 0;
}
void zhongshu(Intercept<int> qian, Intercept<int> a)
{
   Intercept<int> j, c; //i, 
   if (a == 1)
   {
      state[0] = state[0] + 1;
      return;
   }
   for (state[2] = Intercept<int>(qian, 2); state[2] <= a; state[2]++)
   {
      if (a % state[2] == 0)
         zhongshu(state[2], a / state[2]);
   }
}
