#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> ans(Intercept<int> sum, Intercept<int> min)
{
    Intercept<int> intercepts[] = {Intercept<int>(0, 2), Intercept<int>(1, 3), Intercept<int>(1, 5), Intercept<int>(0,7)};
    StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

    //Intercept<int> x; == state[4] //, w, u(1, 3);
    for (state[0] = Intercept<int>(min, 2); state[0] < sum / 2; state[0]++)
    {
        state[4] = sum % state[0];
        if (state[4] == 0)
        {
            if (state[0] <= sum / state[0])
            {
                state[1] += ans(sum / state[0], state[0]);
                state[2] += state[1];
            }
        }
    }
    return state[1];
}

int main()
{
    Intercept<int> intercepts[] = {Intercept<int>(0, 2), Intercept<int>(0, 4)};
    StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

    Intercept<int> a[10000], b[10000], p, q, m; //, n, i, j
    scanf("%d", &state[1]);
    for (state[0] = Intercept<int>(0, 2); state[0] < state[1]; state[0]++)
    {
        scanf("\n%d", &a[state[0]]);
    }
    for (state[0] = 0; state[0] < state[1]; state[0]++)
    {
        printf("%d\n", ans(a[state[0]], 2));
    }
    return 0;
}
