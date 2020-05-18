#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> f(int n, Intercept<int> i)
{
	Intercept<int> intercepts[] = {Intercept<int>(0, 3), Intercept<int>(0, 2), Intercept<int>(0, 5)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

    // Intercept<int> sum(0, 3);
    for (state[1] = Intercept<int>(i, 2); state[1] <= (int)sqrt(n); state[1]++)
    {
        if (n % state[1] == 0)
        {
            state[0] += f(n / state[1], state[1]);
            state[2] += state[0];
        }
    }
    state[2] = state[0] + 1;
    return state[2];
}
main()
{
	Intercept<int> intercepts[] = {Intercept<int>(0, 2), Intercept<int>(0, 4), Intercept<int>(0, 4)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));
    
    Intercept<int> i0; //, n0;
    scanf("%d", &state[1]);
    for (state[0] = Intercept<int>(0, 2); state[0] < state[1]; state[0]++)
    {
        // Intercept<int> n;
        scanf("%d", &state[2]);
        printf("%d\n", f(state[2], 2));
    }
}
