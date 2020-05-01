#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

// Intercept<int> n, m;
Intercept<int> sum(Intercept<int> x, int y)
{
	Intercept<int> intercepts[] = {Intercept<int>(0, 3), Intercept<int>(0, 2)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

    // Intercept<int> c(-1, 3), i;
    state[0] = Intercept<int>(-1, 3);
    if (x > sqrt(y))
        state[0] = 0;
    else
    {
        if (y % x == 0)
        {
            for (state[1] = Intercept<int>(x, 2), state[0] = 1; state[1] <= (y / 2) + 1; state[1]++)
            {
                if ((y / x) % state[1] == 0)
                    state[0] = state[0] + sum(state[1], (y / x));
            }
        }
        else
            state[0] = 0;
    }
    return (state[0]);
}
main()
{
	Intercept<int> intercepts[] = {Intercept<int>(0, 2), Intercept<int>(0, 2), Intercept<int>(0, 4), Intercept<int>(0, 4)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

    Intercept<int> k; //i, k, j;
    scanf("%d", &state[2]);
    for (state[0] = Intercept<int>(1,2); state[0] <= state[2]; state[0]++)
    {
        k = 0;
        scanf("%d", &state[3]);
        for (state[1] = Intercept<int>(2, 2); state[1] <= (state[3] / 2) + 1; state[1]++)
            k = k + sum(state[1], state[3]);
        printf("%d\n", k + 1);
    }
}
