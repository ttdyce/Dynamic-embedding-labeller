#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

// Intercept<int> sum(-1, 3);
Intercept<int> intercepts[] = {Intercept<int>(-1, 3), Intercept<int>(0, 2), Intercept<int>(-1, 2), Intercept<int>(0, 2), Intercept<int>(0, 4), Intercept<int>(1, 5)};
StateIntercept state(intercepts, 1);

void f(Intercept<int> x, Intercept<int> i)
{
    if (x == 1)
        state[0]++;
    else
    {
        for (state[1] = Intercept<int>(state[1], 2); state[1] <= x; state[1]++)
            if (x % state[1] == 0)
                f(x / state[1], state[1]);
    }
}

int main()
{
    cin >> state[2];
    while (state[2] > 0)
    {

        // Intercept<int>i, ans = Intercept<int>(1, 3);// x = 0, 
        cin >> state[4];
        for (state[3] = Intercept<int>(2, 2); state[3] * state[3] < state[4]; state[3]++)
        {
            if (state[4] % state[3] == 0)
            {
                state[0] = 0;
                f(state[4] / state[3], state[3]);
                state[5] += state[0];
            }
        }
        cout << state[5] << endl;
        state[2]--;
    }

    return 0;
}