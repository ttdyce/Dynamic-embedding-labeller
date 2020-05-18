#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

// Intercept<int> sum(-1, 3);
Intercept<int> intercepts[] = {Intercept<int>(-1, 3), Intercept<int>(0, 2), Intercept<int>(0, 2), Intercept<int>(0, 4)};
StateIntercept state(intercepts, sizeof(intercepts)/sizeof(intercepts[0]));

Intercept<int> yin(Intercept<int> c, Intercept<int> g) //?????
{
    Intercept<int> interceptss[] = {Intercept<int>(0,7), Intercept<int>(0,7)};
    StateIntercept states(interceptss, sizeof(interceptss)/sizeof(interceptss[0]));

    Intercept<int>  k; //f = states[1]; //e = states[0]; // j,

    state[1] = Intercept<int>(g, 2);
    for (state[1]; state[1] <= c; state[1]++) //??
    {
        if (c % state[1] == 0)
        {
            states[0] = c / state[1];
            if (states[0] > 1)
            {
                states[1] = state[1];
                yin(states[0], states[1]);
            }
            else
                state[0]++; //?????????
        }
    }
    return state[0]; //??
}
int main()
{
    Intercept<int> a[1000], b[1000]; //d = states[0]; //i, n, 
    Intercept<int> interceptss[] = {Intercept<int>(0,7)};
    StateIntercept states(interceptss, sizeof(interceptss)/sizeof(interceptss[0]));

    cin >> state[3];
    for (state[2]; state[2] < state[3]; state[2]++)
        cin >> a[state[2]]; //??
    for (state[2] = 0; state[2] < state[3]; state[2]++)
    {
        states[0] = 2;
        state[0] = 0;
        b[state[2]] = yin(a[state[2]], states[0]);
    }
    for (state[2] = 0; state[2] < state[3]; state[2]++)
        cout << b[state[2]] << endl; //??
    return 0;
}
