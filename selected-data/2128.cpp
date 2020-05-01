#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> ispr(Intercept<int> t)
{
    Intercept<int> intercepts[] = {Intercept<int>(0, 2)};
    StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

    Intercept<int> v = (int)sqrt(t * 1.0) + 1;
    for (state[0] = Intercept<int>(2, 2); state[0] < v; state[0]++)
        if (t % state[0] == 0)
            return 0;
    return 1;
}

// Intercept<int> sum(-1, 3);
Intercept<int> intercepts[] = {Intercept<int>(-1, 3), Intercept<int>(0, 2), Intercept<int>(0, 2), Intercept<int>(1, 3), Intercept<int>(0, 2), Intercept<int>(0, 4), Intercept<int>(0, 4)};
StateIntercept gState(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

void fun(Intercept<int> n, Intercept<int> i)
{
    if (n == 1)
        gState[0]++;
    for (gState[1] = Intercept<int>(i, 2); gState[1] <= n; gState[1]++)
    {
        if (n % gState[1] == 0)
            fun(n / gState[1], gState[1]);
    }
    return;
}

int main()
{
    // Intercept<int> n;
    scanf("%d", &gState[5]);
    for (gState[2]; gState[2] < gState[5]; gState[2]++)
    {
        // Intercept<int> a;
        scanf("%d", &state[6]);
        if (ispr(state[6]) == 1)
        {
            printf("1\n");
            continue;
        }

        // Intercept<int> res(1, 3);
        for (gState[4] = Intercept<int>(2, 2); gState[4] <= state[6] / 2; gState[4]++)
        {
            if (state[6] % gState[4] == 0)
            {
                gState[0] = 0;
                fun(state[6] / gState[4], gState[4]);
                gState[3] = gState[3] + gState[0];
            }
        }
        printf("%d\n", gState[3]);
    }

    return 0;
}
