#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> divmet(Intercept<int> n, Intercept<int> i);
int main()
{
    Intercept<int> intercepts[] = {Intercept<int>(0, 3), Intercept<int>(0, 2), Intercept<int>(2, 2), Intercept<int>(0, 4), Intercept<int>(0, 4)};
    StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

    // Intercept<int> n = 0; //?????
    // Intercept<int> t = 0; //????
    // Intercept<int> sum(0, 3);   //???????
    cin >> state[3];
    for (state[1]; state[1] < state[3]; state[1]++)
    {
        state[0] = 0;
        cin >> state[4];
        for (state[2]; state[2] <= state[4]; state[2]++)
        {
            state[0] = state[0] + divmet(state[4], state[2]);
        }
        cout << state[0] << endl;
    }
    return 0;
}
Intercept<int> divmet(Intercept<int> n, Intercept<int> i)
{
    Intercept<int> intercepts[] = {Intercept<int>(2, 2), Intercept<int>(0, 6), Intercept<int>(0, 6)};
    StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

    Intercept<int> num = 0;
    if (n % i == 0)
    {
        if (n == i)
        {
            state[1] = 1;
            return 1;
        }
        for (state[0]; state[0] <= i; state[0]++)
        {
            num = num + divmet(n / i, state[0]); //??
        }
        return num;
    }

    else
    {
        state[2] = 1;
        return 0;
    }
}
