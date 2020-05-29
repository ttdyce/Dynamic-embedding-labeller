#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

// Intercept<int> a;
// Intercept<int> res;
// Intercept<int> sum = Intercept<int>(-1, 3);

Intercept<int> intercepts[] = {Intercept<int>(-1, 3), Intercept<int>(0, 2), Intercept<int>(0, 2), Intercept<int>(0, 2), Intercept<int>(0, 4), Intercept<int>(0, 4), Intercept<int>(0, 5)};
StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

void dfs(Intercept<int> cnt)
{
    Intercept<int> interceptss[] = {Intercept<int>(0,7)};
    StateIntercept states(interceptss, sizeof(interceptss) / sizeof(interceptss[0]));

    if (cnt * state[0] == state[5])
    {
        state[6]++;
        return;
    }
    if (cnt * state[0] < state[5])
    {
        state[0] *= cnt;
        //  Intercept<int> j  = states[0]
        states[0] = state[5] / state[0];
        for (state[1] = Intercept<int>(cnt, 2); state[1] <= states[0]; state[1]++)
            dfs(state[1]);
        state[0] /= cnt;
        return;
    }
}
int main()
{
    // Intercept<int> nCases;
    scanf("%d", &state[4]);
    for ( state[2] = Intercept<int>(0, 2); state[2] < state[4]; state[2]++)
    {
        scanf("%d", &state[5]);
        state[6] = 0;
        state[0] = 1;
        for ( state[3] = Intercept<int>(2, 2); state[3] <= state[5]; state[3]++)
            dfs(state[3]);
        printf("%d\n", state[6]);
    }
    return 0;
}
