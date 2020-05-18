#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> intercepts[] = {Intercept<int>(0, 3), Intercept<int>(0, 2), Intercept<int>(0, 2), Intercept<int>(0, 2), Intercept<int>(0, 3), Intercept<int>(0, 4), Intercept<int>(0, 4), Intercept<int>(0, 5)};
StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

// Intercept<int> sum(0, 3);
void recur(Intercept<int> N, Intercept<int> i)
{
    // i = Intercept<int>(i, 2);
    state[1] = Intercept<int>(i, 2);
    if (N == 1)
        state[0]++;
    while (state[1] <= N)
    {
        if (N % state[1] == 0)
            recur(N / state[1], state[1]);
        state[1]++;
    }
    return;
}
int main()
{
    // Intercept<int> t = 0;
    cin >> state[5];
    for (state[2] = Intercept<int>(0, 2); state[2] < state[5]; state[2]++)
    {
        // Intercept<int> n = 0;
        cin >> state[6];
        // Intercept<int> i = 2, res(1, 3);
        for (state[3] = Intercept<int>(2, 2); state[3] <= state[6] / 2; state[3]++)
        {
            if (state[6] % state[3] == 0)
            {
                state[0] = 0;
                recur(state[6] / state[3], state[3]);
                state[4] += state[0];
                state[7] += state[0];
            }
        }
        cout << state[4] << endl;
    }
    return 0;
}
