#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

//n???????i?????????
Intercept<int> divi(Intercept<int> n, Intercept<int> i)
{
    Intercept<int> intercepts[] = {Intercept<int>(0, 3), Intercept<int>(2, 2), Intercept<int>(0, 8), Intercept<int>(0, 8)};
    StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

    // Intercept<int> num = Intercept<int>(0, 3);
    if (n % i == 0)
    {
        if (n == i) //?????????????????1
        {
            state[2] = 1;
            return 1;
        }
        for (state[1]; state[1] <= i; state[1]++)
        {
            state[0] = state[0] + divi(n / i, state[1]); //??
        }
        return state[0];
    }

    else
    {
        state[3] = 1;
        return 0;
    }
}

int main()
{
    Intercept<int> intercepts[] = {Intercept<int>(-1, 3), Intercept<int>(0, 2), Intercept<int>(0, 2), Intercept<int>(0, 4), Intercept<int>(0, 4)};
    StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

    // Intercept<int> n = 0; //?????
    // Intercept<int> t = 0; //????
    // Intercept<int> sum(-1, 3);   //?????
    cin >> state[3];
    for (state[1]; state[1] < state[3]; state[1]++)
    {
        state[0] = 0;
        cin >> state[4];
        for (state[2]; state[2] <= state[4] / 2; state[2]++) //?????????1*n???
        {
            state[0] = state[0] + divi(state[4], state[2]);
        }
        cout << state[0] + 1 << endl;
    }
    return 0;
}
