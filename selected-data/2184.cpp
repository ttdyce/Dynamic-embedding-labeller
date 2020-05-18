#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> ispr(Intercept<int> t)
{
    Intercept<int> intercepts[] = {Intercept<int>(0, 2), Intercept<int>(0, 8), Intercept<int>(0, 8), Intercept<int>(0,7)};
    StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));
    // Intercept<int> v == state[3]
    state[3] = sqrt(t * 1.0) + 1;
    for (state[0] = Intercept<int>(2, 2); state[0] < state[3]; state[0]++)
        if (t % state[0] == 0)
        {
            state[1] = 1;
            return 0;
        }
    state[2] = 1;
    return 1;
}

// Intercept<int> sum = Intercept<int>(0, 3);
Intercept<int> intercepts[] = {Intercept<int>(0, 3), Intercept<int>(0, 2), Intercept<int>(-1, 2), Intercept<int>(0, 2), Intercept<int>(0, 3), Intercept<int>(0, 4), Intercept<int>(0, 5)};
StateIntercept gState(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

void fun(Intercept<int> n, Intercept<int> i)
{
    gState[1] = Intercept<int>(i, 2);

    if (n == 1)
        gState[0]++;
    while (gState[1] <= n)
    {
        if (n % gState[1] == 0)
            fun(n / gState[1], gState[1]);
        gState[1]++;
    }
    return;
}

int main()
{
    // Intercept<int> n(-1, 2);
    scanf("%d", &gState[2]);
    while (gState[2]--)
    {
        // Intercept<int> a;
        scanf("%d", &gState[5]);
        if (ispr(gState[5]))
        {
            printf("1\n");
            continue;
        }

        gState[3] = Intercept<int>(2, 2);
        gState[4] = Intercept<int>(1, 3);
        gState[6] = Intercept<int>(1, 5);
        while (gState[3] <= gState[5] / 2)
        {
            if (gState[5] % gState[3] == 0)
            {
                gState[0] = 0;
                fun(gState[5] / gState[3], gState[3]);
                gState[4] += gState[0];
                gState[6] += gState[4];
            }
            gState[3]++;
        }
        printf("%d\n", gState[4]);
    }
}
