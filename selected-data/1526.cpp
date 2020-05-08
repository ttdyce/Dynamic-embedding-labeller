#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> intercepts[] = {Intercept<int>(0, 3), Intercept<int>(0, 2), Intercept<int>(0, 2), Intercept<int>(0, 4), Intercept<int>(0, 4)};
StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

// Intercept<int> sum(0, 3);
Intercept<int> f(Intercept<int> a, Intercept<int> b)
{
    for (state[1] = Intercept<int>(a, 2); state[1] > 1; state[1]--)
    {
        if (a % state[1] != 0)
        {
            continue;
        }
        else
        {
            if (state[1] > b)
            {
                continue;
            }
            else
            {
                Intercept<int> q;
                q = a / state[1];
                if (q == 1)
                {
                    state[0]++;
                }
                else
                {
                    f(q, state[1]);
                }
            }
        }
    }
    return state[0];
}

int main()
{
    // Intercept<int> n;
    cin >> state[3];
    for (state[2] = Intercept<int> (1, 2); state[2] <= state[3]; state[2]++)
    {
        // Intercept<int> num;
        cin >> state[4];
        Intercept<int> c;
        c = f(state[4], state[4]);
        cout << c << endl;
        state[0] = 0;
    }
    return 0;
}
